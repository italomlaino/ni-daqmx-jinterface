package com.model.datatype;

import com.model.util.Constants;

public enum SampleModeType {

	Finite(Constants.DAQmx_Val_FiniteSamps), Continous(
			Constants.DAQmx_Val_ContSamps), HardwareTimedSinglePoint(
			Constants.DAQmx_Val_HWTimedSinglePoint);

	private int code;

	private SampleModeType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
