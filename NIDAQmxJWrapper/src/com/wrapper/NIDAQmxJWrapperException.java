package com.wrapper;

public class NIDAQmxJWrapperException extends Exception {

	private int code;

	public NIDAQmxJWrapperException(int code, String message) {
		super(message);

		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
