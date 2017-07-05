#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=audio.c buzzer.c i2c.c lcd.c midi.c music.c sdcard.c ShiftRegister.c spi.c xformat.c ../PoC/smartlibc.c events.c main.c pragma.c timer1.c timer4.c timer5.c run_config.c run_free.c run_learn.c run_simon.c run_simon2.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/audio.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/midi.o ${OBJECTDIR}/music.o ${OBJECTDIR}/sdcard.o ${OBJECTDIR}/ShiftRegister.o ${OBJECTDIR}/spi.o ${OBJECTDIR}/xformat.o ${OBJECTDIR}/_ext/1360903477/smartlibc.o ${OBJECTDIR}/events.o ${OBJECTDIR}/main.o ${OBJECTDIR}/pragma.o ${OBJECTDIR}/timer1.o ${OBJECTDIR}/timer4.o ${OBJECTDIR}/timer5.o ${OBJECTDIR}/run_config.o ${OBJECTDIR}/run_free.o ${OBJECTDIR}/run_learn.o ${OBJECTDIR}/run_simon.o ${OBJECTDIR}/run_simon2.o
POSSIBLE_DEPFILES=${OBJECTDIR}/audio.o.d ${OBJECTDIR}/buzzer.o.d ${OBJECTDIR}/i2c.o.d ${OBJECTDIR}/lcd.o.d ${OBJECTDIR}/midi.o.d ${OBJECTDIR}/music.o.d ${OBJECTDIR}/sdcard.o.d ${OBJECTDIR}/ShiftRegister.o.d ${OBJECTDIR}/spi.o.d ${OBJECTDIR}/xformat.o.d ${OBJECTDIR}/_ext/1360903477/smartlibc.o.d ${OBJECTDIR}/events.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/pragma.o.d ${OBJECTDIR}/timer1.o.d ${OBJECTDIR}/timer4.o.d ${OBJECTDIR}/timer5.o.d ${OBJECTDIR}/run_config.o.d ${OBJECTDIR}/run_free.o.d ${OBJECTDIR}/run_learn.o.d ${OBJECTDIR}/run_simon.o.d ${OBJECTDIR}/run_simon2.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/audio.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/midi.o ${OBJECTDIR}/music.o ${OBJECTDIR}/sdcard.o ${OBJECTDIR}/ShiftRegister.o ${OBJECTDIR}/spi.o ${OBJECTDIR}/xformat.o ${OBJECTDIR}/_ext/1360903477/smartlibc.o ${OBJECTDIR}/events.o ${OBJECTDIR}/main.o ${OBJECTDIR}/pragma.o ${OBJECTDIR}/timer1.o ${OBJECTDIR}/timer4.o ${OBJECTDIR}/timer5.o ${OBJECTDIR}/run_config.o ${OBJECTDIR}/run_free.o ${OBJECTDIR}/run_learn.o ${OBJECTDIR}/run_simon.o ${OBJECTDIR}/run_simon2.o

# Source Files
SOURCEFILES=audio.c buzzer.c i2c.c lcd.c midi.c music.c sdcard.c ShiftRegister.c spi.c xformat.c ../PoC/smartlibc.c events.c main.c pragma.c timer1.c timer4.c timer5.c run_config.c run_free.c run_learn.c run_simon.c run_simon2.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX270F256B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/audio.o: audio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/audio.o.d 
	@${RM} ${OBJECTDIR}/audio.o 
	@${FIXDEPS} "${OBJECTDIR}/audio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/audio.o.d" -o ${OBJECTDIR}/audio.o audio.c   -legacy-libc
	
${OBJECTDIR}/buzzer.o: buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	@${FIXDEPS} "${OBJECTDIR}/buzzer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buzzer.o.d" -o ${OBJECTDIR}/buzzer.o buzzer.c   -legacy-libc
	
${OBJECTDIR}/i2c.o: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c.o.d" -o ${OBJECTDIR}/i2c.o i2c.c   -legacy-libc
	
${OBJECTDIR}/lcd.o: lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/lcd.o.d" -o ${OBJECTDIR}/lcd.o lcd.c   -legacy-libc
	
${OBJECTDIR}/midi.o: midi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/midi.o.d 
	@${RM} ${OBJECTDIR}/midi.o 
	@${FIXDEPS} "${OBJECTDIR}/midi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/midi.o.d" -o ${OBJECTDIR}/midi.o midi.c   -legacy-libc
	
${OBJECTDIR}/music.o: music.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/music.o.d 
	@${RM} ${OBJECTDIR}/music.o 
	@${FIXDEPS} "${OBJECTDIR}/music.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/music.o.d" -o ${OBJECTDIR}/music.o music.c   -legacy-libc
	
${OBJECTDIR}/sdcard.o: sdcard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sdcard.o.d 
	@${RM} ${OBJECTDIR}/sdcard.o 
	@${FIXDEPS} "${OBJECTDIR}/sdcard.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sdcard.o.d" -o ${OBJECTDIR}/sdcard.o sdcard.c   -legacy-libc
	
${OBJECTDIR}/ShiftRegister.o: ShiftRegister.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ShiftRegister.o.d 
	@${RM} ${OBJECTDIR}/ShiftRegister.o 
	@${FIXDEPS} "${OBJECTDIR}/ShiftRegister.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ShiftRegister.o.d" -o ${OBJECTDIR}/ShiftRegister.o ShiftRegister.c   -legacy-libc
	
${OBJECTDIR}/spi.o: spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi.o.d 
	@${RM} ${OBJECTDIR}/spi.o 
	@${FIXDEPS} "${OBJECTDIR}/spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi.o.d" -o ${OBJECTDIR}/spi.o spi.c   -legacy-libc
	
${OBJECTDIR}/xformat.o: xformat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/xformat.o.d 
	@${RM} ${OBJECTDIR}/xformat.o 
	@${FIXDEPS} "${OBJECTDIR}/xformat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/xformat.o.d" -o ${OBJECTDIR}/xformat.o xformat.c   -legacy-libc
	
${OBJECTDIR}/_ext/1360903477/smartlibc.o: ../PoC/smartlibc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360903477" 
	@${RM} ${OBJECTDIR}/_ext/1360903477/smartlibc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360903477/smartlibc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360903477/smartlibc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360903477/smartlibc.o.d" -o ${OBJECTDIR}/_ext/1360903477/smartlibc.o ../PoC/smartlibc.c   -legacy-libc
	
${OBJECTDIR}/events.o: events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/events.o.d 
	@${RM} ${OBJECTDIR}/events.o 
	@${FIXDEPS} "${OBJECTDIR}/events.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/events.o.d" -o ${OBJECTDIR}/events.o events.c   -legacy-libc
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   -legacy-libc
	
${OBJECTDIR}/pragma.o: pragma.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pragma.o.d 
	@${RM} ${OBJECTDIR}/pragma.o 
	@${FIXDEPS} "${OBJECTDIR}/pragma.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pragma.o.d" -o ${OBJECTDIR}/pragma.o pragma.c   -legacy-libc
	
${OBJECTDIR}/timer1.o: timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1.o 
	@${FIXDEPS} "${OBJECTDIR}/timer1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer1.o.d" -o ${OBJECTDIR}/timer1.o timer1.c   -legacy-libc
	
${OBJECTDIR}/timer4.o: timer4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer4.o.d 
	@${RM} ${OBJECTDIR}/timer4.o 
	@${FIXDEPS} "${OBJECTDIR}/timer4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer4.o.d" -o ${OBJECTDIR}/timer4.o timer4.c   -legacy-libc
	
${OBJECTDIR}/timer5.o: timer5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer5.o.d 
	@${RM} ${OBJECTDIR}/timer5.o 
	@${FIXDEPS} "${OBJECTDIR}/timer5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer5.o.d" -o ${OBJECTDIR}/timer5.o timer5.c   -legacy-libc
	
${OBJECTDIR}/run_config.o: run_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_config.o.d 
	@${RM} ${OBJECTDIR}/run_config.o 
	@${FIXDEPS} "${OBJECTDIR}/run_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_config.o.d" -o ${OBJECTDIR}/run_config.o run_config.c   -legacy-libc
	
${OBJECTDIR}/run_free.o: run_free.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_free.o.d 
	@${RM} ${OBJECTDIR}/run_free.o 
	@${FIXDEPS} "${OBJECTDIR}/run_free.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_free.o.d" -o ${OBJECTDIR}/run_free.o run_free.c   -legacy-libc
	
${OBJECTDIR}/run_learn.o: run_learn.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_learn.o.d 
	@${RM} ${OBJECTDIR}/run_learn.o 
	@${FIXDEPS} "${OBJECTDIR}/run_learn.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_learn.o.d" -o ${OBJECTDIR}/run_learn.o run_learn.c   -legacy-libc
	
${OBJECTDIR}/run_simon.o: run_simon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_simon.o.d 
	@${RM} ${OBJECTDIR}/run_simon.o 
	@${FIXDEPS} "${OBJECTDIR}/run_simon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_simon.o.d" -o ${OBJECTDIR}/run_simon.o run_simon.c   -legacy-libc
	
${OBJECTDIR}/run_simon2.o: run_simon2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_simon2.o.d 
	@${RM} ${OBJECTDIR}/run_simon2.o 
	@${FIXDEPS} "${OBJECTDIR}/run_simon2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_simon2.o.d" -o ${OBJECTDIR}/run_simon2.o run_simon2.c   -legacy-libc
	
else
${OBJECTDIR}/audio.o: audio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/audio.o.d 
	@${RM} ${OBJECTDIR}/audio.o 
	@${FIXDEPS} "${OBJECTDIR}/audio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/audio.o.d" -o ${OBJECTDIR}/audio.o audio.c   -legacy-libc
	
${OBJECTDIR}/buzzer.o: buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	@${FIXDEPS} "${OBJECTDIR}/buzzer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buzzer.o.d" -o ${OBJECTDIR}/buzzer.o buzzer.c   -legacy-libc
	
${OBJECTDIR}/i2c.o: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c.o.d" -o ${OBJECTDIR}/i2c.o i2c.c   -legacy-libc
	
${OBJECTDIR}/lcd.o: lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/lcd.o.d" -o ${OBJECTDIR}/lcd.o lcd.c   -legacy-libc
	
${OBJECTDIR}/midi.o: midi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/midi.o.d 
	@${RM} ${OBJECTDIR}/midi.o 
	@${FIXDEPS} "${OBJECTDIR}/midi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/midi.o.d" -o ${OBJECTDIR}/midi.o midi.c   -legacy-libc
	
${OBJECTDIR}/music.o: music.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/music.o.d 
	@${RM} ${OBJECTDIR}/music.o 
	@${FIXDEPS} "${OBJECTDIR}/music.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/music.o.d" -o ${OBJECTDIR}/music.o music.c   -legacy-libc
	
${OBJECTDIR}/sdcard.o: sdcard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sdcard.o.d 
	@${RM} ${OBJECTDIR}/sdcard.o 
	@${FIXDEPS} "${OBJECTDIR}/sdcard.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sdcard.o.d" -o ${OBJECTDIR}/sdcard.o sdcard.c   -legacy-libc
	
${OBJECTDIR}/ShiftRegister.o: ShiftRegister.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ShiftRegister.o.d 
	@${RM} ${OBJECTDIR}/ShiftRegister.o 
	@${FIXDEPS} "${OBJECTDIR}/ShiftRegister.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ShiftRegister.o.d" -o ${OBJECTDIR}/ShiftRegister.o ShiftRegister.c   -legacy-libc
	
${OBJECTDIR}/spi.o: spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi.o.d 
	@${RM} ${OBJECTDIR}/spi.o 
	@${FIXDEPS} "${OBJECTDIR}/spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi.o.d" -o ${OBJECTDIR}/spi.o spi.c   -legacy-libc
	
${OBJECTDIR}/xformat.o: xformat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/xformat.o.d 
	@${RM} ${OBJECTDIR}/xformat.o 
	@${FIXDEPS} "${OBJECTDIR}/xformat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/xformat.o.d" -o ${OBJECTDIR}/xformat.o xformat.c   -legacy-libc
	
${OBJECTDIR}/_ext/1360903477/smartlibc.o: ../PoC/smartlibc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360903477" 
	@${RM} ${OBJECTDIR}/_ext/1360903477/smartlibc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360903477/smartlibc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360903477/smartlibc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360903477/smartlibc.o.d" -o ${OBJECTDIR}/_ext/1360903477/smartlibc.o ../PoC/smartlibc.c   -legacy-libc
	
${OBJECTDIR}/events.o: events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/events.o.d 
	@${RM} ${OBJECTDIR}/events.o 
	@${FIXDEPS} "${OBJECTDIR}/events.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/events.o.d" -o ${OBJECTDIR}/events.o events.c   -legacy-libc
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   -legacy-libc
	
${OBJECTDIR}/pragma.o: pragma.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pragma.o.d 
	@${RM} ${OBJECTDIR}/pragma.o 
	@${FIXDEPS} "${OBJECTDIR}/pragma.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pragma.o.d" -o ${OBJECTDIR}/pragma.o pragma.c   -legacy-libc
	
${OBJECTDIR}/timer1.o: timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer1.o.d 
	@${RM} ${OBJECTDIR}/timer1.o 
	@${FIXDEPS} "${OBJECTDIR}/timer1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer1.o.d" -o ${OBJECTDIR}/timer1.o timer1.c   -legacy-libc
	
${OBJECTDIR}/timer4.o: timer4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer4.o.d 
	@${RM} ${OBJECTDIR}/timer4.o 
	@${FIXDEPS} "${OBJECTDIR}/timer4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer4.o.d" -o ${OBJECTDIR}/timer4.o timer4.c   -legacy-libc
	
${OBJECTDIR}/timer5.o: timer5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer5.o.d 
	@${RM} ${OBJECTDIR}/timer5.o 
	@${FIXDEPS} "${OBJECTDIR}/timer5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer5.o.d" -o ${OBJECTDIR}/timer5.o timer5.c   -legacy-libc
	
${OBJECTDIR}/run_config.o: run_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_config.o.d 
	@${RM} ${OBJECTDIR}/run_config.o 
	@${FIXDEPS} "${OBJECTDIR}/run_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_config.o.d" -o ${OBJECTDIR}/run_config.o run_config.c   -legacy-libc
	
${OBJECTDIR}/run_free.o: run_free.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_free.o.d 
	@${RM} ${OBJECTDIR}/run_free.o 
	@${FIXDEPS} "${OBJECTDIR}/run_free.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_free.o.d" -o ${OBJECTDIR}/run_free.o run_free.c   -legacy-libc
	
${OBJECTDIR}/run_learn.o: run_learn.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_learn.o.d 
	@${RM} ${OBJECTDIR}/run_learn.o 
	@${FIXDEPS} "${OBJECTDIR}/run_learn.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_learn.o.d" -o ${OBJECTDIR}/run_learn.o run_learn.c   -legacy-libc
	
${OBJECTDIR}/run_simon.o: run_simon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_simon.o.d 
	@${RM} ${OBJECTDIR}/run_simon.o 
	@${FIXDEPS} "${OBJECTDIR}/run_simon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_simon.o.d" -o ${OBJECTDIR}/run_simon.o run_simon.c   -legacy-libc
	
${OBJECTDIR}/run_simon2.o: run_simon2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run_simon2.o.d 
	@${RM} ${OBJECTDIR}/run_simon2.o 
	@${FIXDEPS} "${OBJECTDIR}/run_simon2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run_simon2.o.d" -o ${OBJECTDIR}/run_simon2.o run_simon2.c   -legacy-libc
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -legacy-libc  -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -legacy-libc -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Software.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
