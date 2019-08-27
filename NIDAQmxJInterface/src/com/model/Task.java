package com.model;

import com.exception.GenericException;
import com.model.channel.ai.AIChannelManager;
import com.model.channel.ao.AOChannelManager;
import com.model.datatype.TaskActionType;
import com.model.timing.Timing;
import com.wrapper.NIDAQmxJWrapper;
import com.wrapper.NIDAQmxJWrapperException;

public class Task {

	private long pointer;

	private AIChannelManager aiChannelManager;
	private AOChannelManager aoChannelManager;
	private Timing timing;

	public Task(String name) throws GenericException {
		try {
			pointer = NIDAQmxJWrapper.createTask(name);

			aiChannelManager = new AIChannelManager(this);
			aoChannelManager = new AOChannelManager(this);
			timing = new Timing(this);
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public void start() throws GenericException {
		try {
			NIDAQmxJWrapper.startTask(pointer);
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public void stop() throws GenericException {
		try {
			NIDAQmxJWrapper.stopTask(pointer);
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public void dispose() throws GenericException {
		try {
			NIDAQmxJWrapper.clearTask(pointer);
			pointer = 0;
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public String getName() throws GenericException {
		try {
			String name = NIDAQmxJWrapper.getTaskName(pointer);

			return name;
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public void control(TaskActionType action) throws GenericException {
		try {
			NIDAQmxJWrapper.taskControl(pointer, action.getCode());
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public AIChannelManager getAIChannelManager() {
		return aiChannelManager;
	}

	public AOChannelManager getAOChannelManager() {
		return aoChannelManager;
	}

	public Timing getTiming() {
		return timing;
	}

	public long getPointer() {
		return pointer;
	}
}