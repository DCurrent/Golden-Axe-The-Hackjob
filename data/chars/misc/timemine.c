

void cast(void self, void p)
{
	char name = getentityproperty(p, "name");
	void e;
	
	clearspawnentry();
	if(name=="Ax_Battler")
	{
		setspawnentry("name", "explarge");
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x"), getentityproperty(self, "z")+1, getentityproperty(self, "a"));
	    changeentityproperty(e, "base", getentityproperty(e, "a"));
		changeentityproperty(e, "animation", A_IDLE);
	}
	else if(name=="Tyris_Flare")
	{
		setspawnentry("name", "firefountain");
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x"), getentityproperty(self, "z"), getentityproperty(self, "a"));
		changeentityproperty(e, "animation", A_RESPAWN);
		setspawnentry("name", "firespirit");
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")+30, getentityproperty(self, "z")-10, getentityproperty(self, "a"));
	    changeentityproperty(e, "direction", 1);
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")+60, getentityproperty(self, "z"), getentityproperty(self, "a"));
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")-30, getentityproperty(self, "z")-10, getentityproperty(self, "a"));
	    changeentityproperty(e, "direction", 1);
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")+30, getentityproperty(self, "z")-10, getentityproperty(self, "a"));
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")-60, getentityproperty(self, "z"), getentityproperty(self, "a"));
	    changeentityproperty(e, "direction", 1);
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")-30, getentityproperty(self, "z")+10, getentityproperty(self, "a"));
	}
	else
	{
		setspawnentry("name", "lightning2");
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")-10, getentityproperty(self, "z")+5, getentityproperty(self, "a"));
	    changeentityproperty(e, "base", getentityproperty(e, "a"));
	    changeentityproperty(e, "direction", 1);
        e = spawn();
	    changeentityproperty(e, "position", getentityproperty(self, "x")+10, getentityproperty(self, "z")-5, getentityproperty(self, "a"));
	    changeentityproperty(e, "base", getentityproperty(e, "a"));
	    changeentityproperty(e, "direction", 0);
	}
}

void blowup()
{
	void self = getlocalvar("self");
	void target = findtarget(self);
	if(target!=NULL())
	{
		if(getentityproperty(target, "defaultname")!="Thief")
		{
			int x1 = getentityproperty(self, "x");
			int x2 = getentityproperty(target, "x");
			int z1 = getentityproperty(self, "z");
			int z2 = getentityproperty(target, "z");
			if(z1 - z2 >-24 && z1 - z2 <24 && x1 - x2 > -48 && x1 - x2 < 48)
			{
				int i;
				void p;
				for(i=0; i<3; i++)
				{
					p = getplayerproperty(i, "ent");
					if(p!=NULL()){cast(self, p);break;}
				}

				killentity(self);
			}
		}
	}
}

