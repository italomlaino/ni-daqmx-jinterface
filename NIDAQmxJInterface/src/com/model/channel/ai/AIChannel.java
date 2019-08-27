package com.model.channel.ai;

import com.exception.GenericException;
import com.model.Task;
import com.model.channel.AChannel;
import com.wrapper.NIDAQmxJWrapper;
import com.wrapper.NIDAQmxJWrapperException;

public abstract class AIChannel extends AChannel {

	public AIChannel(Task task, String name) {
		super(task, name);
	}

	@Override
	public double getMinValue() throws GenericException {
		try {
			return NIDAQmxJWrapper.getAIMin(getTask().getPointer(), getName());
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	@Override
	public void setMinValue(double value) throws GenericException {
		try {
			NIDAQmxJWrapper.setAIMin(getTask().getPointer(), getName(), value);
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	@Override
	public double getMaxValue() throws GenericException {
		try {
			return NIDAQmxJWrapper.getAIMax(getTask().getPointer(), getName());
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	@Override
	public void setMaxValue(double value) throws GenericException {
		try {
			NIDAQmxJWrapper.setAIMax(getTask().getPointer(), getName(), value);
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}
}
