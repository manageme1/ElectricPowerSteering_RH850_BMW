@ECHO off

REM *******************************************************************************************************************
REM * Copyright 2016 Nexteer
REM * Nexteer Confidential
REM *
REM * Module File Name:   XcpIf_Generate.bat
REM * Module Description: Generates component configuration files.  Generated from TL109A_SwcSuprt.
REM * Project:            CBD
REM * Author:             Owen Tosh
REM *******************************************************************************************************************

SETLOCAL

REM get arguments
SET ECUC_FILE=%1
SET GENDATA_FOLDER=%2

REM set up paths
SET ARTT_TOOLS_PATH=..\..\..\TL105A_Artt\tools

REM clean up existing configuration files
IF EXIST "%GENDATA_FOLDER%\CDD_XcpIf_Cfg.h" DEL "%GENDATA_FOLDER%\CDD_XcpIf_Cfg.h"
IF EXIST "%GENDATA_FOLDER%\CDD_XcpIf_Cfg_private.h" DEL "%GENDATA_FOLDER%\CDD_XcpIf_Cfg_private.h"
IF EXIST "%GENDATA_FOLDER%\CDD_XcpIf_DataAcqnCfg.arxml" DEL "%GENDATA_FOLDER%\CDD_XcpIf_DataAcqnCfg.arxml"
IF EXIST "%GENDATA_FOLDER%\CDD_XcpIf_DataAcqnCfg.m" DEL "%GENDATA_FOLDER%\CDD_XcpIf_DataAcqnCfg.m"

REM generate CDD_XcpIf_Cfg.h.tt
SET ERRORLEVEL=
%ARTT_TOOLS_PATH%\artt.exe -d="%ECUC_FILE%" -t=.\CDD_XcpIf_Cfg.h.tt -i=%ARTT_TOOLS_PATH%\include -u="http://autosar.org/schema/r4.0" -o="%GENDATA_FOLDER%" >> "%GENDATA_FOLDER%\CDD_XcpIf_Cfg.h.tt.log" 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end

REM generate CDD_XcpIf_Cfg_private.h.tt
SET ERRORLEVEL=
%ARTT_TOOLS_PATH%\artt.exe -d="%ECUC_FILE%" -t=.\CDD_XcpIf_Cfg_private.h.tt -i=%ARTT_TOOLS_PATH%\include -u="http://autosar.org/schema/r4.0" -o="%GENDATA_FOLDER%" >> "%GENDATA_FOLDER%\CDD_XcpIf_Cfg_private.h.tt.log" 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end

REM generate CDD_XcpIf_DataAcqnCfg.arxml.tt
SET ERRORLEVEL=
%ARTT_TOOLS_PATH%\artt.exe -d="%ECUC_FILE%" -t=.\CDD_XcpIf_DataAcqnCfg.arxml.tt -i=%ARTT_TOOLS_PATH%\include -u="http://autosar.org/schema/r4.0" -o="%GENDATA_FOLDER%" >> "%GENDATA_FOLDER%\CDD_XcpIf_DataAcqnCfg.arxml.tt.log" 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end

REM generate CDD_XcpIf_DataAcqnCfg.m.tt
SET ERRORLEVEL=
%ARTT_TOOLS_PATH%\artt.exe -d="%ECUC_FILE%" -t=.\CDD_XcpIf_DataAcqnCfg.m.tt -i=%ARTT_TOOLS_PATH%\include -u="http://autosar.org/schema/r4.0" -o="%GENDATA_FOLDER%" >> "%GENDATA_FOLDER%\CDD_XcpIf_DataAcqnCfg.m.tt.log" 2>>&1
IF %ERRORLEVEL% NEQ 0 GOTO end


:end
EXIT %ERRORLEVEL%
ENDLOCAL
