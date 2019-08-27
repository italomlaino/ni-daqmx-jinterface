package com.model.datatype;

import com.model.util.Constants;

public enum TaskActionType {

	Start(Constants.DAQmx_Val_Task_Start), Stop(Constants.DAQmx_Val_Task_Stop), Verify(
			Constants.DAQmx_Val_Task_Verify), Commit(
			Constants.DAQmx_Val_Task_Commit), Reserve(
			Constants.DAQmx_Val_Task_Reserve), Unreserve(
			Constants.DAQmx_Val_Task_Unreserve), Abort(
			Constants.DAQmx_Val_Task_Abort);

	private int code;

	private TaskActionType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
