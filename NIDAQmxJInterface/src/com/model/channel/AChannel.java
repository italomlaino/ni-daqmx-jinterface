package com.model.channel;

import com.exception.GenericException;
import com.model.Task;

public abstract class AChannel extends Channel {

	public AChannel(Task task, String name) {
		super(task, name);
	}

	public abstract double getMaxValue() throws GenericException;

	public abstract void setMaxValue(double value) throws GenericException;

	public abstract double getMinValue() throws GenericException;

	public abstract void setMinValue(double value) throws GenericException;
}
