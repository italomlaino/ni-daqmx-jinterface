package com.model.channel.ao;

import com.model.Task;
import com.model.channel.AChannel;

public abstract class AOChannel extends AChannel {

	public AOChannel(Task task, String name) {
		super(task, name);
	}
}
