package com.exception;

public class GenericException extends Exception {

	public GenericException(Exception e) {
		super(e.getMessage());
	}
}
