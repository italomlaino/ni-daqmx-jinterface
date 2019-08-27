package com.samples;

import com.exception.GenericException;
import com.model.Task;
import com.model.datatype.ActiveEdgeType;
import com.model.datatype.FillModeType;
import com.model.datatype.SampleModeType;
import com.model.datatype.ShuntResistorLocType;
import com.model.datatype.TerminalConfigType;
import com.model.datatype.unit.CurrentUnitType;
import com.model.reader.AnalogChannelReader;

public class ReadCurrentSample {

	public static void main(String[] args) {
		// createCurrentChannel
		// Par�metros para configura��o do canal
		String physicalChannel = "Dev1/ai0"; // Nome do canal f�sico
		String nameToAssignToChannel = ""; // Nome a ser setado ao canal virtual
		TerminalConfigType terminalConfig = TerminalConfigType.Cfg_Default;
		double minVal = 0.0; // Valor m�nimo
		double maxVal = 0.02; // Valor m�ximo
		CurrentUnitType currentUnit = CurrentUnitType.Amps;
		ShuntResistorLocType shuntResistorLoc = ShuntResistorLocType.Default;
		String customScaleName = null; // Nome da escala personalizada

		// cfgSampClkTiming
		// Par�metros para configura��o do rel�gio de amostras
		String source = "";
		double rate = 1000.0;
		long sampsPerChan = 1000;
		ActiveEdgeType activeEdge = ActiveEdgeType.Rising;
		SampleModeType sampleMode = SampleModeType.Finite;

		// readAnalogF64
		// Par�metros para configura��o do leitor
		double timeOut = 10.0; // Tempo minimo de espera
		FillModeType fillMode = FillModeType.GroupByChannel;

		try {
			// Cria a tarefa
			Task task = new Task("ReadCurrentSample");

			// Cria o canal de voltagem
			task.getAIChannelManager().createCurrentChannel(physicalChannel,
					nameToAssignToChannel, terminalConfig, minVal, maxVal,
					currentUnit, shuntResistorLoc, 249.0, customScaleName);

			// Configura o relogio de amostra
			task.getTiming().configSampleClock(source, rate, activeEdge,
					sampleMode, sampsPerChan);

			// Inicia a tarefa
			task.start();

			// Cria o leitor
			AnalogChannelReader reader = new AnalogChannelReader(task, timeOut,
					fillMode);

			// L�
			double data[] = reader.readF64((int) sampsPerChan);

			// Imprime
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < data.length; i++) {
				sb.append("[");
				sb.append(i);
				sb.append("]: ");
				sb.append(data[i]);
				sb.append(" A");
				sb.append("\n");
			}

			System.out.println(sb.toString());

		} catch (GenericException e) {
			e.printStackTrace();
		}
	}
}
