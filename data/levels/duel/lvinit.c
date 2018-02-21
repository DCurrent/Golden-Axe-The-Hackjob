void main()
{

	int i; int j;
	void p;
	for(i=0; i<3; i++)
	{
		p = getplayerproperty(i, "ent");
		if(p!=NULL())
		{
			for(j = 0; j<15; j++)
			{
				changeentityproperty(p, "defense", j, -100);
			}
		}
	}
    changeplayerproperty(0, "credits", 0);
	    
    setglobalvar("player0mp", 0);
    setglobalvar("player1mp", 0);
    setglobalvar("player2mp", 0);    
    setglobalvar("wake", NULL());

}