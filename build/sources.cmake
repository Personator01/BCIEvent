set(SOURCES_CPP 
	../src/Actor.cpp
	../src/application/BCIEventApplication.cpp
	../src/application/AppInitPartial.cpp
	../src/blocks/EndBlock.cpp
	../src/blocks/EventCallerBlock.cpp
	../src/blocks/HeadBlock.cpp
	../src/blocks/IfBlock.cpp
	../src/blocks/IfElseBlock.cpp
	../src/blocks/LoopBlock.cpp
	../src/blocks/NormalBlock.cpp
	../src/blocks/TimedBlock.cpp
	../src/blocks/TimerBlock.cpp
	../src/blocks/WhileLoopBlock.cpp
	../src/builder/SequenceBuilder.cpp
	../src/state/BCIState.cpp
	../src/state/States.cpp
	../src/variable/GlobalVariables.cpp
	../src/event/EventListener.cpp
	../src/event/Event.cpp
    )


set(INCLUDE_BCI
    src/shared/modules
    src/shared/modules/application
    src/shared/gui
    src/shared/utils
    src/shared/utils/AV
    src/shared/utils/Lib
    src/shared/utils/Expression
    src/shared/types/
    src/shared/accessors/
    src/shared/config/
    src/shared/bcistream/
    src/shared/filters/
    src/shared/state/
    src/shared/fileio
    src/shared/modules/application/gui
    )
    

set(SOURCES_BCI 
    src/shared/gui/GUI.cpp
    src/shared/gui/GraphObject.cpp
    src/shared/gui/GraphDisplay.cpp
    src/shared/gui/Bitmap.cpp
    src/shared/gui/DisplayWindow.cpp
    src/shared/gui/DisplayClock.cpp
    src/shared/gui/SpinningWheel.cpp
    src/shared/gui/DisplayStatisticsField.cpp
    src/shared/gui/TextField.cpp
    src/shared/gui/OpenGLContext.cpp
    src/shared/types/SignalProperties.cpp
    src/shared/types/GenericSignal.cpp
    src/shared/types/BitmapImage.cpp
    src/shared/types/State.cpp
    src/shared/types/StateList.cpp
    src/shared/types/Param.cpp
    src/shared/types/ParamList.cpp
    src/shared/types/LabelIndex.cpp
    src/shared/types/Label.cpp
    src/shared/types/Status.cpp
    src/shared/types/SysCommand.cpp
    src/shared/types/PhysicalUnit.cpp
    src/shared/types/EncodedString.cpp
    src/shared/types/SignalType.cpp
    src/shared/types/StateVector.cpp
    src/shared/types/HierarchicalLabel.cpp
    src/shared/types/GenericVisualization.cpp
    src/shared/types/Brackets.cpp
    src/shared/types/VisID.cpp
    src/shared/utils/Directory.cpp
    src/shared/utils/RandomGenerator.cpp
    src/shared/utils/EventQueue.cpp
    src/shared/utils/LogFile.cpp
    src/shared/utils/PrecisionTime.cpp
    src/shared/utils/QtProxyThread.cpp
    src/shared/utils/MeasurementUnits.cpp
    src/shared/utils/ClockTick.cpp
    src/shared/utils/AV/AudioSink.cpp
    src/shared/utils/AV/AudioDevice.cpp
    src/shared/utils/Expression/ArithmeticExpression.cpp
    src/shared/utils/Expression/ExpressionParser.cpp
    src/shared/utils/Expression/ExpressionNodes.cpp
    src/shared/fileio/RequiredParameters.cpp
    src/shared/fileio/RunManager.cpp
    src/shared/bcistream/BCIStream_guiapp.cpp
    src/shared/bcistream/BCIStream.cpp
    src/shared/accessors/Environment.cpp
    src/shared/accessors/StateRef.cpp
    src/shared/accessors/ParamRef.cpp
    src/shared/accessors/BCIEvent.cpp
    src/shared/modules/application/ApplicationBase.cpp
    src/shared/modules/MessageChannel.cpp
    src/shared/modules/application/gui/ApplicationWindow.cpp
    src/shared/filters/GenericFilter.cpp
    )
