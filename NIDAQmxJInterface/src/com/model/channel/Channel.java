package com.model.channel;

import com.model.Task;

public abstract class Channel {

	private Task task;
	private String name;

	public Channel(Task task, String name) {
		this.task = task;
		this.name = name;
	}

	public Task getTask() {
		return task;
	}

	public String getName() {
		return name;
	}
}
