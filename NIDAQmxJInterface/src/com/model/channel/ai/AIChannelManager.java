package com.model.channel.ai;

import com.exception.GenericException;
import com.model.Task;
import com.model.channel.ChannelManager;
import com.model.datatype.BridgeConfigType;
import com.model.datatype.ExcitationSourceType;
import com.model.datatype.ShuntResistorLocType;
import com.model.datatype.TerminalConfigType;
import com.model.datatype.unit.CurrentUnitType;
import com.model.datatype.unit.ElectricalUnitType;
import com.model.datatype.unit.PhysicalUnitType;
import com.model.datatype.unit.TorqueUnitType;
import com.model.datatype.unit.VelocitySensivityUnitType;
import com.model.datatype.unit.VelocityUnitType;
import com.model.datatype.unit.VoltageUnitType;
import com.wrapper.NIDAQmxJWrapper;
import com.wrapper.NIDAQmxJWrapperException;

public class AIChannelManager extends ChannelManager {

	public AIChannelManager(Task task) {
		super(task);
	}

	public AIChannel createCurrentChannel(String physicalChannel,
			String nameToAssignToChannel, TerminalConfigType terminalConfig,
			double minVal, double maxVal, CurrentUnitType units,
			ShuntResistorLocType shuntResistorLoc, double extShuntResistorVal,
			String customScaleName) throws GenericException {

		try {
			NIDAQmxJWrapper.createAICurrentChan(getTask().getPointer(),
					physicalChannel, nameToAssignToChannel,
					terminalConfig.getCode(), minVal, maxVal, units.getCode(),
					shuntResistorLoc.getCode(), extShuntResistorVal,
					customScaleName);

			AICurrentChannel channel = new AICurrentChannel(getTask(),
					nameToAssignToChannel);

			return channel;

		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public AIChannel createCurrentRMSChannel(String physicalChannel,
			String nameToAssignToChannel, TerminalConfigType terminalConfig,
			double minVal, double maxVal, CurrentUnitType units,
			ShuntResistorLocType shuntResistorLoc, double extShuntResistorVal,
			String customScaleName) throws GenericException {

		try {
			NIDAQmxJWrapper.createAICurrentRMSChan(getTask().getPointer(),
					physicalChannel, nameToAssignToChannel,
					terminalConfig.getCode(), minVal, maxVal, units.getCode(),
					shuntResistorLoc.getCode(), extShuntResistorVal,
					customScaleName);

			AICurrentChannel channel = new AICurrentChannel(getTask(),
					nameToAssignToChannel);

			return channel;

		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public AIChannel createTorqueBridgePolynomialChannel(
			String physicalChannel, String nameToAssignToChannel,
			double minVal, double maxVal, TorqueUnitType units,
			BridgeConfigType bridgeConfig,
			ExcitationSourceType voltageExcitSource, double voltageExcitVal,
			double nominalBridgeResistance, double[] forwardCoeffs,
			double[] reverseCoeffs, ElectricalUnitType electricalUnits,
			PhysicalUnitType physicalUnits, String customScaleName)
			throws GenericException {

		try {
			NIDAQmxJWrapper.createAITorqueBridgePolynomialChan(getTask()
					.getPointer(), physicalChannel, nameToAssignToChannel,
					minVal, maxVal, units.getCode(), bridgeConfig.getCode(),
					voltageExcitSource.getCode(), voltageExcitVal,
					nominalBridgeResistance, forwardCoeffs, reverseCoeffs,
					electricalUnits.getCode(), physicalUnits.getCode(),
					customScaleName);

			AITorqueChannel channel = new AITorqueChannel(getTask(),
					nameToAssignToChannel);
			getChannels().add(channel);

			return channel;
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public AIChannel createTorqueBridgeTableChannel(String physicalChannel,
			String nameToAssignToChannel, double minVal, double maxVal,
			TorqueUnitType units, BridgeConfigType bridgeConfig,
			ExcitationSourceType voltageExcitSource, double voltageExcitVal,
			double nominalBridgeResistance, double[] electricalVals,
			ElectricalUnitType electricalUnits, double[] physicalVals,
			PhysicalUnitType physicalUnits, String customScaleName)
			throws GenericException {

		try {
			NIDAQmxJWrapper.createAITorqueBridgeTableChan(getTask()
					.getPointer(), physicalChannel, nameToAssignToChannel,
					minVal, maxVal, units.getCode(), bridgeConfig.getCode(),
					voltageExcitSource.getCode(), voltageExcitVal,
					nominalBridgeResistance, electricalVals, electricalUnits
							.getCode(), physicalVals, physicalUnits.getCode(),
					customScaleName);

			AITorqueChannel channel = new AITorqueChannel(getTask(),
					nameToAssignToChannel);
			getChannels().add(channel);

			return channel;
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public AIChannel createTorqueBridgeTwoPointLinChan(String physicalChannel,
			String nameToAssignToChannel, double minVal, double maxVal,
			TorqueUnitType units, BridgeConfigType bridgeConfig,
			ExcitationSourceType voltageExcitSource, double voltageExcitVal,
			double nominalBridgeResistance, double firstElectricalVal,
			double secondElectricalVal, ElectricalUnitType electricalUnits,
			double firstPhysicalVal, double secondPhysicalVal,
			PhysicalUnitType physicalUnits, String customScaleName)
			throws GenericException {

		try {
			NIDAQmxJWrapper.createAITorqueBridgeTwoPointLinChan(getTask()
					.getPointer(), physicalChannel, nameToAssignToChannel,
					minVal, maxVal, units.getCode(), bridgeConfig.getCode(),
					voltageExcitSource.getCode(), voltageExcitVal,
					nominalBridgeResistance, firstElectricalVal,
					secondElectricalVal, electricalUnits.getCode(),
					firstPhysicalVal, secondPhysicalVal, physicalUnits
							.getCode(), customScaleName);

			AITorqueChannel channel = new AITorqueChannel(getTask(),
					nameToAssignToChannel);
			getChannels().add(channel);

			return channel;
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public AIChannel createVelocityIEPEChan(String physicalChannel,
			String nameToAssignToChannel, TerminalConfigType terminalConfig,
			double minVal, double maxVal, VelocityUnitType units,
			double sensitivity, VelocitySensivityUnitType sensitivityUnits,
			ExcitationSourceType currentExcitSource, double currentExcitVal,
			String customScaleName) throws GenericException {

		try {
			NIDAQmxJWrapper.createAIVelocityIEPEChan(getTask().getPointer(),
					physicalChannel, nameToAssignToChannel,
					terminalConfig.getCode(), minVal, maxVal, units.getCode(),
					sensitivity, sensitivityUnits.getCode(),
					currentExcitSource.getCode(), currentExcitVal,
					customScaleName);

			AIVelocityChannel channel = new AIVelocityChannel(getTask(),
					nameToAssignToChannel);
			getChannels().add(channel);

			return channel;
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}

	public AIChannel createVoltageChannel(String physicalChannel,
			String nameToAssignToChannel, TerminalConfigType terminalConfig,
			double minVal, double maxVal, VoltageUnitType units,
			String customScaleName) throws GenericException {
		try {
			NIDAQmxJWrapper.createAIVoltageChan(getTask().getPointer(),
					physicalChannel, nameToAssignToChannel,
					terminalConfig.getCode(), minVal, maxVal, units.getCode(),
					customScaleName);

			AIVoltageChannel channel = new AIVoltageChannel(getTask(),
					nameToAssignToChannel);
			getChannels().add(channel);

			return channel;
		} catch (NIDAQmxJWrapperException e) {
			throw new GenericException(e);
		}
	}
}