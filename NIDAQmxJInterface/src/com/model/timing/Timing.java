package com.model.timing;

import com.exception.GenericException;
import com.model.Task;
import com.model.datatype.ActiveEdgeType;
import com.model.datatype.SampleModeType;
import com.wrapper.NIDAQmxJWrapper;
import com.wrapper.NIDAQmxJWrapperException;

public class Timing {

	private Task task;

	public Timing(Task task) {
		this.task = task;
	}

	public void configSampleClock(String source, double rate,
			ActiveEdgeType activeEdge, SampleModeType sampleMode,
			long sampsPerChan) throws GenericException {
		try {
			NIDAQmxJWrapper.cfgSampClkTiming(task.getPointer(), source, rate,
					activeEdge.getCode(), sampleMode.getCode(), sampsPerChan);
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public Task getTask() {
		return task;
	}
}
