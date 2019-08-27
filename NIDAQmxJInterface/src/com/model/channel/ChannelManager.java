package com.model.channel;

import java.util.ArrayList;
import java.util.List;

import com.model.Task;

public class ChannelManager {

	private Task task;
	private List<Channel> channels;

	public ChannelManager(Task task) {
		this.task = task;

		channels = new ArrayList<>();
	}

	public Task getTask() {
		return task;
	}

	public Channel getChannel(String name) {
		for (Channel channel : channels) {
			if (channel.getName().equals(name)) {
				return channel;
			}
		}

		return null;
	}

	public List<Channel> getChannels() {
		return channels;
	}
}
