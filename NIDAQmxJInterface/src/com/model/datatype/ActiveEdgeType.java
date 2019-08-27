package com.model.datatype;

import com.model.util.Constants;

public enum ActiveEdgeType {

	Rising(Constants.DAQmx_Val_Rising), Falling(Constants.DAQmx_Val_Falling);

	private int code;

	private ActiveEdgeType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
