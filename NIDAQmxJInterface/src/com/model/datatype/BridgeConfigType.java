package com.model.datatype;

import com.model.util.Constants;

public enum BridgeConfigType {

	FullBridge(Constants.DAQmx_Val_FullBridge), HalfBridge(
			Constants.DAQmx_Val_HalfBridge), QuarterBridge(
			Constants.DAQmx_Val_QuarterBridge);

	private int code;

	private BridgeConfigType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
