package com.model.datatype;

import com.model.util.Constants;

public enum FillModeType {

	GroupByChannel(Constants.DAQmx_Val_GroupByChannel), GroupByScanNumber(
			Constants.DAQmx_Val_GroupByScanNumber);

	private boolean code;

	private FillModeType(boolean code) {
		this.code = code;
	}

	public boolean getCode() {
		return code;
	}
}
