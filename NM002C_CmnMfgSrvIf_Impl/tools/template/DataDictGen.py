"""=====================================================================================================================
#      File: DataDictGen.py
#   Project: EA4 Manufacturing Services
#    Author: Jared Julien <jared.julien@nexteer.com>
# Copyright: (c) 2018 Nexteer Automotive
#
# Description:
# ------------
# Given an ODX file as input, generate the Data Dictionary for the CmnMfgSrvIf component suitable for use by the
# Software Architecture team.  The generated file contains all of the server runnables generated by DcmSrcGen along with
# all of the corresponding input/output arguments applicable to each.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2018-02-02  1     Jared     Initial file creation
# -------------------------------------------------------------------------------------------------------------------"""
# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import argparse
import logging
import os
import sys
import datetime

# Installed Dependencies
from mako.lookup import TemplateLookup  # https://pypi.python.org/pypi/Mako/

# Local imports
import common

# Imports from TL113A Component
# pylint: disable=F0401
# pylint: disable=C0413
# Pylint doesn't understand where to find them.
sys.path.insert(0, os.path.join('..', '..', '..', 'TL113A_MfgSrvSuprt', 'tools'))
import bindings.odx
import libraries.services
import libraries.files



# ======================================================================================================================
# Runnable Model Class
# ----------------------------------------------------------------------------------------------------------------------
class Runnable(object):
    """Model representing a server runnable with optional input/output arguments."""
    def __init__(self, sid, suffix):
        self.name = 'CmnMfgSrvIf_Srv0x%04X%s' % (sid, suffix)
        self.has_error = True
        self.input_name = None
        self.output_name = None
        self.input_length = 1
        self.output_length = 1

    @property
    def has_input(self):
        """Returns boolean True when this runnable has input data."""
        return self.input_name is not None

    @property
    def has_output(self):
        """Return boolean True when this runnable has output data."""
        return self.output_name is not None


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def generate_datadict(runnables):
    """Generate and return the data dict .m file for which this script is intended to produce."""
    # Derive the path to template files as relative to this file.  Mako assumes that templates are relative to the
    # directory from which the script is called which is likely to be in a component folder where the batch files is
    # located rather than here.
    directory = os.path.dirname(os.path.realpath(__file__))
    lookup = TemplateLookup(directories=[directory])
    mytemplate = lookup.get_template('NM002C_CmnMfgSrvIf_DataDict.m.tpl')
    year = datetime.datetime.now().strftime('%Y')
    return mytemplate.render(runnables=runnables, year=year).replace('\r', '')

# ----------------------------------------------------------------------------------------------------------------------
def parse_runnables(routines, iocs, pids):
    """Helper function that converts routine, IOC, and PID services into a single list of server runnables that will be
    defined by this component."""
    runnables = []
    for routine in routines:
        if routine.start:
            runnable = Runnable(routine.sid, 'Strt')
            if routine.start.in_length > 0:
                runnable.input_name = 'DcmDspStartRoutineInSignal'
                runnable.input_length = routine.start.in_bytes
            if routine.start.out_length > 0:
                runnable.output_name = 'DcmDspStartRoutineOutSignal'
                runnable.output_length = routine.start.out_bytes
            runnables.append(runnable)
        if routine.stop:
            runnable = Runnable(routine.sid, 'Stop')
            if routine.stop.in_length > 0:
                runnable.input_name = 'DcmDspRoutineStopInSignal'
                runnable.input_length = routine.stop.in_bytes
            if routine.stop.out_length > 0:
                runnable.output_name = 'DcmDspRoutineStopOutSignal'
                runnable.output_length = routine.stop.out_bytes
            runnables.append(runnable)
        if routine.result:
            runnable = Runnable(routine.sid, 'Sts')
            if routine.result.in_length > 0:
                runnable.input_name = 'DcmDspRoutineRequestResInSignal'
                runnable.input_length = routine.result.in_bytes
            if routine.result.out_length > 0:
                runnable.output_name = 'DcmDspRoutineRequestResOutSignal'
                runnable.output_length = routine.result.out_bytes
            runnables.append(runnable)
    for ioc in iocs:
        if ioc.take:
            runnable = Runnable(ioc.sid, 'Adj')
            runnable.input_name = 'Data'
            runnable.input_length = ioc.take.in_bytes
            runnables.append(runnable)
        if ioc.release:
            runnable = Runnable(ioc.sid, 'Rtn')
            runnables.append(runnable)
    for pid in pids:
        if pid.read:
            runnable = Runnable(pid.sid, 'Rd')
            runnable.output_name = 'Data'
            runnable.output_length = pid.read.out_bytes
            runnable.has_error = False
            runnables.append(runnable)
        if pid.write:
            runnable = Runnable(pid.sid, 'Wr')
            runnable.input_name = 'Data'
            runnable.input_length = pid.write.in_bytes
            runnables.append(runnable)
    return runnables


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    description = "Nexteer ODX to DCM Interface Source Utility - EA4 Manufacturing Services"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-v', '--verbose', default=0, action='count', help='Output detailed information to console')
    parser.add_argument('input', help='Input ODX file containing all services to be generated')
    parser.add_argument('output', help='Output data dict .m file name')
    args = parser.parse_args()

    # Setup logging
    levels = [logging.WARNING, logging.INFO, logging.DEBUG]
    logLevel = levels[min(args.verbose, 2)]
    logging.basicConfig(level=logLevel)

    # Read input file
    logging.info('Reading input file: %s', args.input)
    with open(args.input) as inFile:
        odxText = inFile.read()
    cms = bindings.odx.CreateFromDocument(odxText)

    # Convert ODX to list of services
    variant = cms.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
    services = []
    for diag in variant.DIAG_COMMS.DIAG_SERVICE:
        if '_NoResponse' not in diag.SHORT_NAME:
            service = libraries.services.Service(diag, variant)
            services.append(service)

    # Convert services into objects specific to this template.
    routineServices = common.parse_routines(services)
    iocServices = common.parse_iocs(services)
    pidServices = common.parse_pids(services)

    # Convert different services into list runnables.
    servers = parse_runnables(routineServices, iocServices, pidServices)

    # Generate XML
    m = generate_datadict(servers)

    # Write output file
    libraries.files.backup(args.output)
    with open(args.output, 'w+') as outFile:
        outFile.write(m)
    logging.info('Output written to: %s', args.output)


# End of File: DataDictGen.py
