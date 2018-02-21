
int keyd001(int iIndex, int iNewKey, void vSelf){
     
     /*
     keyd001
     Damon Vaughn Caskey
     05/13/2007     
     Wrapper for players keys function, returns integer based on key pressed.
     
     iIndex: Player index for key press.
     iNewKey: New key press or "holding".
     vSelf: Target entity. 
     */
                  
     if (getentityproperty(vSelf, "direction")==1 && (playerkeys(iIndex,iNewKey, "moveright")))     { return 10; } //"Forward" (facing right).
     else if (getentityproperty(vSelf, "direction")==0 && (playerkeys(iIndex,iNewKey, "moveleft"))) { return 10; } //"Forward" (facing left).               
     else if (getentityproperty(vSelf, "direction")==1 && (playerkeys(iIndex,iNewKey, "moveleft"))){     
         if (playerkeys(iIndex, iNewKey, "attack")){ 
            return 13;  //"Back + Attack".
         }else{
            return 11; //"Back" (facing right).
         }
     }
     else if (getentityproperty(vSelf, "direction")==0 && 
         (playerkeys(iIndex,iNewKey, "moveright")))     {   return 11;  }   //"Back" (facing left).                    
     else if (playerkeys(iIndex, iNewKey, "moveleft"))  {   return 1;   }   //Left.                                    
     else if (playerkeys(iIndex, iNewKey, "moveright")) {   return 2;   }   //Right                     
     else if (playerkeys(iIndex, iNewKey, "moveup"))    {   return 3;   }   //Up.     
     else if (playerkeys(iIndex, iNewKey, "movedown"))  {   return 4;   }   //Down.     
     else if (playerkeys(iIndex, iNewKey, "esc"))       {   return 5;   }   //Escape.     
     else if (playerkeys(iIndex, iNewKey, "start"))     {   return 6;   }   //Start.     
     else if (playerkeys(iIndex, iNewKey, "special"))   {   return 7;   }   //Special.                             
     else if (playerkeys(iIndex, iNewKey, "jump"))      {   return 8;   }   //Jump.     
     else if (playerkeys(iIndex,iNewKey, "attack"))     {   return 9;   }   //Attack 1.                    
     else if (playerkeys(iIndex,0, "jump") && 
         playerkeys(iIndex,0, "special"))               {   return 12;  }   //Jump + Special
     
}