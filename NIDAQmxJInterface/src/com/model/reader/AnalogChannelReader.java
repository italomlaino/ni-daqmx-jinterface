package com.model.reader;

import com.exception.GenericException;
import com.model.Task;
import com.model.datatype.FillModeType;
import com.wrapper.NIDAQmxJWrapper;
import com.wrapper.NIDAQmxJWrapperException;

public class AnalogChannelReader extends ChannelReader {

	private double timeout;
	private FillModeType fillMode;

	public AnalogChannelReader(Task task, double timeout, FillModeType fillMode) {
		super(task);

		this.timeout = timeout;
		this.fillMode = fillMode;
	}

	public double[] readF64(int numSamps) throws GenericException {
		try {
			return NIDAQmxJWrapper.readAnalogF64(getTask().getPointer(),
					numSamps, timeout, fillMode.getCode());
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}
}
