int main()
{
	int input=0, output=0, stageA=0, stageB=0;
	
	Analog analog;
	Delay delays[3];

	while(1)
	{
		input = analog.read();
		input = 2 * delays[0].process(input) + input;
		stageA = delays[1].process(output);
		stageB = 1.5 * stageA - 0.9 * delays[2].process(stageA);
		output = input + stageB;
		analog.write(output);
	}
}