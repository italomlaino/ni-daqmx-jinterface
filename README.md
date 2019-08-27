Objectives
	- Implement all these basic functions:
		// Task
		DAQmxCreateTask
		DAQmxStartTask
		DAQmxStopTask
		DAQmxClearTask
		DAQmxIsTaskDone
		DAQmxTaskControl
		DAQmxGetTaskName
		DAQmxGetTaskChannels
		DAQmxGetTaskNumChans
		DAQmxGetTaskDevices
		DAQmxGetTaskNumDevices

		// Channel
		DAQmxResetChanAttribute
		DAQmxCreateAIVoltageChan
		DAQmxCreateAICurrentChan
		DAQmxCreateAITorqueBridgePolynomialChan
		DAQmxCreateAIVelocityIEPEChan

		// Timing
		DAQmxCfgSampClkTiming

		// Reading
		DAQmxReadAnalogF64

		// System
		DAQmxGetSysScales
		DAQmxGetSysTasks

		// Error Handling
		DAQmxGetErrorString
		DAQmxGetExtendedErrorInfo

Simulation System
	- Windows XP Pro SP3
	- NI-DAQmx 9.6.1


Restrictions
	- Support only for Windows 


ToDo
	- Get a new project name, maybe NIDAQmxJWrapper (Done!)
	- Migrate from Visual Studio to Eclipse (Done!)
	- Find all dependencies to deploy to a machine without Visual Studio (Done!)
	- Implement Exception (Done!)
	- Change folder name from NIDAQmxJWrapper to NIDAQmxJWrapperNative, and NIDAQmxJWrapper-Java to NIDAQmxJWrapper (Done!)
	
	- Implement Warnings Events
	- Implement a better design (task.getName(), task.AIChannel.createVoltageChannel())
	- Implement continuous reading