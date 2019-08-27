package com.model.datatype;

import com.model.util.Constants;

public enum ShuntResistorLocType {

	Default(Constants.DAQmx_Val_Default), Internal(Constants.DAQmx_Val_Internal), External(
			Constants.DAQmx_Val_External);

	private int code;

	private ShuntResistorLocType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
