int main()
{
	int input=0, output=0, stageA=0, stageB=0;
	
	Analog analog;
	Delay delays[2];

	while(1)
	{
		input = analog.read();
		stageA = delays[0].process(output);
		stageB = 0.5 * (stageA + delays[1].process(stageA));
		output = input + stageB;
		analog.write(output);
	}
}