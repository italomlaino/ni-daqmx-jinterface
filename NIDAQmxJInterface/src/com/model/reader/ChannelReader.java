package com.model.reader;

import com.model.Task;

public abstract class ChannelReader {

	private Task task;

	public ChannelReader(Task task) {
		this.task = task;
	}

	public Task getTask() {
		return task;
	}
}
