/*
  ==============================================================================

    SynthSound.h
    Created: 28 Sep 2021 3:15:29pm
    Author:  abao

  ==============================================================================
*/

#pragma once
class SynthSound : public juce::SynthesiserSound
{

public:
	bool appliesToNote(int midiNoteNumber) override
	{
		return true;
	}

	bool appliesToChannel(int midiNoteNumber) override
	{
		return true;
	}
};