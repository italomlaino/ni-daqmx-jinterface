package com.model.datatype;

import com.model.util.Constants;

public enum ExcitationSourceType {
	None(Constants.DAQmx_Val_None), Internal(Constants.DAQmx_Val_Internal), External(
			Constants.DAQmx_Val_External);

	private int code;

	private ExcitationSourceType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
