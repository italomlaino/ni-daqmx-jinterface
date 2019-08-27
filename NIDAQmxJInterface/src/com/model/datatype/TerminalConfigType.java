package com.model.datatype;

import com.model.util.Constants;

public enum TerminalConfigType {

	Cfg_Default(Constants.DAQmx_Val_Cfg_Default), RSE(Constants.DAQmx_Val_RSE), NRSE(
			Constants.DAQmx_Val_NRSE), Diff(Constants.DAQmx_Val_Diff), PseudoDiff(
			Constants.DAQmx_Val_PseudoDiff);

	private int code;

	private TerminalConfigType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
