#ifndef DC_FIDELITY_CONFIG

#define DC_FIDELITY_CONFIG 1

#include "data/scripts/dc_instance/main.c"
#include "data/scripts/dc_d20/main.c"

/** Library Name
* 
* Used mainly as a base for variable IDs. Must
* be unique vs all other libraries. Try to keep it short.
**/
#define DC_FIDELITY_BASE_ID		"dcfid"

/** Max Volume
* 
* This is the max volume engine allows for sound effects. 
* In theory we don't need this. The engine allows us to 
* read the menu option for sound volume. Unfortunatly there
* is a hidden hard coded volume cap applied to all sounds
* during playback. This is done for backward compatibility 
* with older modules, but it does present a problem for us.
* 
* Chiefly, the menu values are almost always much higher than 
* the hard code limit. As a result, our own calculations 
* might produce "low" values that also exceed the hard code 
* limit. When we play our sound, the engine subsequently 
* caps the playback volume and so our dynamic volume 
* calculations appear to fail.
* 
* To solve this problem, we include a value here that at time
* of writing is identical to engine’s hidden volume cap. When
* we request current volume level from the engine, we’ll cap 
* the result to this value before beginning any calculations. 
* This ensures our calculations stay within the engine cap 
* while also respecting player wishes if they set a lower 
* volume in the menu.
* 
* If later engine updates allow higher volume, we can increase 
* or eliminate this fix.
**/
#define DC_FIDELITY_ENGINE_MAX_VOLUME 64

/* 
* Logging. 
*
* Enable flags to log events.
*/

#define DC_FIDELITY_LOG_LOAD							1	// Loading and setup of sound files.
#define DC_FIDELITY_LOG_BALANCE_INVALID_ENTITY			1	// Entity is not valid pointer (probably NULL). 
#define DC_FIDELITY_LOG_CATEGORY_MISSING				1   // Category argument is blank. 
#define DC_FIDELITY_LOG_CATEGORY_TYPE_NOT_FOUND			1	// Specified category (containing a type list) not found.
#define DC_FIDELITY_LOG_PLAY							1	// Sound plays.
#define DC_FIDELITY_LOG_UNLOAD							1	// Unloading of sounds.
#define DC_FIDELITY_LOG_TIMED_SETUP						1	// Set up timed delay sound.
				

/** Sound Categories
*
* Normally sound categories are the name of a model. 
* When an entity is instructed to play
* a type of sound (see below), we use its base
* model name to select the category. This is not a 
* requirement though, it is just the default
* behavior. You can load sounds with any category 
* name you like and override the sound system's 
* automatic category selection when playing a 
* sound type.
*
* This is a list of predefined custom categories. 
* One example might be global whiff or hit sounds. 
* You aren't required to use this list when you 
* create custom categories, but it's a good idea 
* just to keep yourself organized. Add as many
* categories as you wish, just make sure they are 
* unique to each other and don't match any of your 
* model names.
*
* Note: DC_FIDELITY_CATEGORY_GLOBAL is a special category 
* used as a default fallback (you can switch this behavior 
* off). If a sound type does not exist for the requested 
* category, the sound system will look for that type in 
* the global category instead. If the type is not found 
* in global category either, no sound is played.
**/
#define DC_FIDELITY_CATEGORY_GLOBAL			0
#define DC_FIDELITY_CATEGORY_MALE			1
#define DC_FIDELITY_CATEGORY_FEMALE			2

/** Sound Types
*
* Sound types are the specific types of sounds you 
* assign to each category (see above), and then instruct 
* the sound system to play. For instance, a model's
* voice effect when making a heavy attack. Each type 
* can be loaded mutiple times with different sound 
* files, in which case the sound will be picked 
* randomly each time the play function is executed.
*
* As with categories, feel free to create and use
* sound types at your discretion. 
**/

/** Sound effects. **/
#define DC_FIDELITY_TYPE_SOUND_SPAWN				0	// Spawn sound.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY			1	// "Air" sound, heavy attacks.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY_BLADE	2	// "Air" sound, heavy attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT			3	// "Air" sound, light attacks.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT_BLADE	4	// "Air" sound, light attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM		5	// "Air" sound, medium attacks.
#define DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE	6	// "Air" sound, medium attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_IMPACT_HEAVY			7	// Attack hit sound, heavy attacks.
#define DC_FIDELITY_TYPE_SOUND_IMPACT_HEAVY_BLADE	8	// Attack hit sound, heavy attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_IMPACT_LIGHT			9	// Attack hit sound, light attacks.
#define DC_FIDELITY_TYPE_SOUND_IMPACT_LIGHT_BLADE	10	// Attack hit sound, light attacks (blade).
#define DC_FIDELITY_TYPE_SOUND_IMPACT_MEDIUM		11	// Attack hit sound, medium attacks.
#define DC_FIDELITY_TYPE_SOUND_IMPACT_MEDIUM_BLADE	12	// Attack hit sound, medium attacks (blade).

#define DC_FIDELITY_TYPE_SOUND_ELETRCITY_0			"elec_0"

/** Voices. **/
#define DC_FIDELITY_TYPE_VOICE_ATTACK_COMMAND		13	// Attack saying. - "Let's get them!", or "Ready your weapon! Let's go!"
#define DC_FIDELITY_TYPE_VOICE_ATTACK_FAIL			14	// Attack did nothing.- "This guy is invincible!", "Oh crap, not a scratch!", ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY	15	// Yalp while attacking. - Ha! ya! ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT	16	// Yalp while attacking. - Ha! ya! ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM	17	// Yalp while attacking. - Ha! ya! ...
#define DC_FIDELITY_TYPE_VOICE_ATTACK_TAUNT			18	// Successful attack (KO for players, knockdown for AI). - "That was too easy!", "Fall before me!", ...
#define DC_FIDELITY_TYPE_VOICE_BAD_IDEA				19	// Skeptical, negative saying. - "That's a stupid plan.", "Lay off the crack pipe.", ...
#define DC_FIDELITY_TYPE_VOICE_BATTLE_CRY			20	// In battle rally. - "I'll kick your ass!", "No one shall default us!", ...
#define DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT			21	// In battle taunt (Ex. After a knockdown) - "You suck!", "Take that loser!", ...
#define DC_FIDELITY_TYPE_VOICE_BORED				22	// Bored saying. - "For fighters we seem to be doing little fighting", "This is certainly one way of not getting anywhere.", ...
#define DC_FIDELITY_TYPE_VOICE_CAN_DO				23	// Comply to a task request. - "Sure thing, I'll take care of it.", "I got this.", ...
#define DC_FIDELITY_TYPE_VOICE_CANT_DO				24	// Can't do a task. - "Sorry, no can do.", "No I can't do that.", ...
#define DC_FIDELITY_TYPE_VOICE_CHEER				25	// Exclamation of joy saying. - "Hurrah!", "Yes! All right!.", ...
#define DC_FIDELITY_TYPE_VOICE_CUSS					26	// Pissed off. - "Damn it!", "Son of a bitch!", ...
#define DC_FIDELITY_TYPE_VOICE_ENCUMBERED			27	// Load is too heavy. - "I'm not a pack mule!", "I have to lighten this load!", ...
#define DC_FIDELITY_TYPE_VOICE_ENEMIES				28	// Spotted opponents. - "There's the enemy.", "That's them up a ahead.", ...
#define DC_FIDELITY_TYPE_VOICE_FLEE					29	// Run! - "We're outmatched, let's beat it!", "Every man for himself!", ...
#define DC_FIDELITY_TYPE_VOICE_FOLLOW_ME			30	// Request to follow. - "Come with me please.", "Stay close behind me.", ...		
#define DC_FIDELITY_TYPE_VOICE_GOOD_BYE				31	// Farewell greeting. - "Until we meet again.", "See you later.", ...
#define DC_FIDELITY_TYPE_VOICE_GOOD_IDEA			32	// Agree with plan. - "That's a fine idea.", "Good thinking!", ...
#define DC_FIDELITY_TYPE_VOICE_GROUP				33	// Form up. - "Close ranks quickly.", "Everyone to me!", ...
#define DC_FIDELITY_TYPE_VOICE_GUARD_ME				34	// Request protection. - "Watch over me.", "You take first watch.", ...
#define DC_FIDELITY_TYPE_VOICE_HEAL_ME				35	// Request healing aid. - "I need medical help!", "Patch me up!", ...	
#define DC_FIDELITY_TYPE_VOICE_HELLO				36	// Conversation greeting. - "Hello there.", "Well met friend.", ...
#define DC_FIDELITY_TYPE_VOICE_HELP					37	// Request assistence. - "I need some help!", "Lend me your skill!", ...
#define DC_FIDELITY_TYPE_VOICE_HIDE					38	// Request stealth - "Be quick and quiet.", "Keep it down everyone.", ...
#define DC_FIDELITY_TYPE_VOICE_HOLD					39	// Request to hold ground. - "Hold your position.", "Wait here a moment.", ...
#define DC_FIDELITY_TYPE_VOICE_KO					40	// Defeated by standard means.
#define DC_FIDELITY_TYPE_VOICE_KO_PIT				41	// Defeated by falling into pit, thrown great distance, etc. - "Ahhhhhhhhhhhhhhhhhhh!", "Noooooooooooooooo!", ...
#define DC_FIDELITY_TYPE_VOICE_LAUGH				42	// Amused laughing.
#define DC_FIDELITY_TYPE_VOICE_LOOK_HERE			43	// Found something. - "Everyone, look at this.", "I see something in the bush.", ...
#define DC_FIDELITY_TYPE_VOICE_MOVE_OVER			44	// Move out of the way. - "Let me pass.", "Please step aside.", ...
#define DC_FIDELITY_TYPE_VOICE_NEAR_KO				45	// Damaged at low HP. - "I'm in big trouble here!", "I can't take another hit like that!", ...
#define DC_FIDELITY_TYPE_VOICE_NO					46	// Negative response. - "Of course not.", "No.", ... 
#define DC_FIDELITY_TYPE_VOICE_PAIN					47	// Taking damage. - "Oof!", "Ow!", ...
#define DC_FIDELITY_TYPE_VOICE_PAIN_FALL			48	// Taking damage and knocked down. - "Oof!", "Ow!", ...
#define DC_FIDELITY_TYPE_VOICE_PAIN_BURN			49	// Taking damage from fire or heat. - "Yarrrrrgh!", "I'm on fire!", ...
#define DC_FIDELITY_TYPE_VOICE_PAIN_SHOCK			50	// Taking damage from electricity. - "Bzzzt", "Ooooh, sparky!", ...
#define DC_FIDELITY_TYPE_VOICE_PICK_LOCK			51	// Request to open a lock. - "Anyone got a key?", "Can you get this open?"
#define DC_FIDELITY_TYPE_VOICE_POISONED				52	// Noticed poision - "I don't feel so good...", "I've been envenomed.", ...
#define DC_FIDELITY_TYPE_VOICE_REST					53	// Request a rest. - "Time for a break.", "Let's rest here a moment.", ...
#define DC_FIDELITY_TYPE_VOICE_SEARCH				54	// Request an area search. - "Let's look around a bit.", "Don't leave a stone un-turned.", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTION_GREET		55	// Highlighted at selection screen. - "Hey, pick me!", "You can't pass up on this!", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTION_PICK		56	// Choosen by player at select screen. - "Nice choice!", "OK, let's do it!", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTION_WAIT		57	// Waiting after highlighted at selection screen. - "Make up your mind man!", "What are you waiting for?", ...
#define DC_FIDELITY_TYPE_VOICE_SELECTED				58	// Reactive greeting. - "Is there something you need?", "Yes? Can I help you?", ...
#define DC_FIDELITY_TYPE_VOICE_SPAWN_NEW			59	// Spawn new. "Let's begin.", "I am ready.", ...
#define DC_FIDELITY_TYPE_VOICE_SPAWN_RETURN			60	// Resapwn after defeat or leaving. - "Now it's my turn.", "We're not done!", ...
#define DC_FIDELITY_TYPE_VOICE_SPELL_FAILED			61	// Magic or special attack fails, can't be used. - "I don't have the energy for that.", "My magic has failed me!", ...
#define DC_FIDELITY_TYPE_VOICE_STOP					62	// Stop request. - "Stop right there.", "Hold up a second!", ...
#define DC_FIDELITY_TYPE_VOICE_TALK_TO_ME			63	// Request to talk. - "We need to chat.", "Please have a word with me.", ...
#define DC_FIDELITY_TYPE_VOICE_TASK_COMPLETE		64	// Task finished. - "All done.", "Finished. What's next?", ...
#define DC_FIDELITY_TYPE_VOICE_TAUNT				65	// Taunt opponent. - "Bring it on chump!", "You don't have a prayer.", ...
#define DC_FIDELITY_TYPE_VOICE_THANKS				66	// Express gratitude. - "I apprciate that.", "Thank you so much.", ...
#define DC_FIDELITY_TYPE_VOICE_THREATEN				67	// Warning. - "You're messing with the wrong guy.", "Keep it up and I'll knock you into last week, so you can wait until now for me to kick your ass again!"
#define DC_FIDELITY_TYPE_VOICE_YES					68	// Agree. - "Sure.", "Yes.", ...

/** Operation flags
*
* These flags control general operation and
* default behaviors. You should leave them
* alone unles you really know what you're doing.
**/

/** Options **/
#define DC_FIDELITY_INDEX_RANDOM	-1		// Seek a random sound index from sound type.
#define DC_FIDELITY_SAMPLE_NONE		-1		// No sample, or invalid sample.		

/** Default values **/
#define DC_FIDELITY_DEFAULT_ENT								getlocalvar("self")
#define DC_FIDELITY_DEFAULT_CATEGORY_LIST					NULL()
#define DC_FIDELITY_DEFAULT_GLOBAL_FALLBACK					1		// Try global category when specific category doesn't have sound type.
#define DC_FIDELITY_DEFAULT_SOUND_CHANCE					1.0
#define DC_FIDELITY_DEFAULT_SOUND_LOCATION_BALANCE			1		// Adjust volume based on a given X position in relation to screen.
#define DC_FIDELITY_DEFAULT_SOUND_LOCATION_FADE				0		// Adjust volume based on a given Z position in relation to screen.
#define DC_FIDELITY_DEFAULT_SOUND_LOCATION_POS_X			openborvariant("hresolution") / 2	// Default X position to use for sound balance when entity position is not available.
#define DC_FIDELITY_DEFAULT_SOUND_LOOP						0
#define DC_FIDELITY_DEFAULT_SOUND_PRIORITY					1
#define DC_FIDELITY_DEFAULT_SOUND_SPEED						100
#define DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT				openborvariant("effectvol") 
#define DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT				openborvariant("effectvol")
#define DC_FIDELITY_DEFAULT_TIMED_LIST						NULL()


/** Static values **/
#define DC_FIDELITY_TIMED_SAMPLE_ARRAY_SIZE	3
#define DC_FIDELITY_TIMED_SAMPLE_SAMPLE_ID	0
#define DC_FIDELITY_TIMED_SAMPLE_TIME		1
#define DC_FIDELITY_TIMED_SAMPLE_ENTITY		2

/** Variable keys **/
#define DC_FIDELITY_MEMBER_ENT								DC_FIDELITY_BASE_ID + 0		
#define DC_FIDELITY_MEMBER_GLOBAL_FALLBACK					DC_FIDELITY_BASE_ID + 1	
#define DC_FIDELITY_MEMBER_SOUND_CATEGORY					DC_FIDELITY_BASE_ID + 2		// Global var used to store list of categories -> types ->indexes.
#define DC_FIDELITY_MEMBER_SOUND_CHANCE						DC_FIDELITY_BASE_ID + 3
#define DC_FIDELITY_MEMBER_SOUND_ELEMENT					DC_FIDELITY_BASE_ID + 4
#define DC_FIDELITY_MEMBER_SOUND_ENTITY						DC_FIDELITY_BASE_ID + 5
#define DC_FIDELITY_MEMBER_SOUND_LOCATION_BALANCE			DC_FIDELITY_BASE_ID + 6
#define DC_FIDELITY_MEMBER_SOUND_LOCATION_FADE				DC_FIDELITY_BASE_ID + 7
#define DC_FIDELITY_MEMBER_SOUND_LOOP						DC_FIDELITY_BASE_ID + 8
#define DC_FIDELITY_MEMBER_SOUND_PRIORITY					DC_FIDELITY_BASE_ID + 9
#define DC_FIDELITY_MEMBER_SOUND_SPEED						DC_FIDELITY_BASE_ID + 10
#define DC_FIDELITY_MEMBER_SOUND_VOLUME_MAIN_LEFT			DC_FIDELITY_BASE_ID + 11	// Left channel volume before any adjustments are made.
#define DC_FIDELITY_MEMBER_SOUND_VOLUME_MAIN_RIGHT			DC_FIDELITY_BASE_ID + 12	// Right channel volume before any adjustments are made.
#define DC_FIDELITY_MEMBER_TIMED_LIST						DC_FIDELITY_BASE_ID + 13	// Global var used to store list of samples to play at later time.
#define DC_FIDELITY_MEMBER_THE_END							14							// Should always be last, with a value one higher than previous key ID.

/** Instance control 
* 
* Instance control allows us to run more than 
* one copy (instance) of a library without the
* instances conflicting with each other. 
* 
* To avoid repeat code, there is a library 
* dedicated specifically to instance control. 
* This section overrides local function names
* with instance control library functions to 
* simplify use of the the instance control 
* library.
**/ 
#define dc_fidelity_get_instance()		dc_instance_get(DC_FIDELITY_BASE_ID)
#define dc_fidelity_set_instance(value) dc_instance_set(DC_FIDELITY_BASE_ID, value)
#define dc_fidelity_reset_instance()	dc_instance_reset(DC_FIDELITY_BASE_ID, DC_FIDELITY_MEMBER_THE_END)
#define dc_fidelity_free_instance()		dc_instance_free(DC_FIDELITY_BASE_ID, DC_FIDELITY_MEMBER_THE_END)
#define dc_fidelity_dump_instance()		dc_instance_dump(DC_FIDELITY_BASE_ID, DC_FIDELITY_MEMBER_THE_END)
#define dc_fidelity_export_instance()	dc_instance_export(DC_FIDELITY_BASE_ID, DC_FIDELITY_MEMBER_THE_END)
#define dc_fidelity_import_instance()	dc_instance_import(DC_FIDELITY_BASE_ID, DC_FIDELITY_MEMBER_THE_END)
#define dc_fidelity_free_export()		dc_instance_free_export(DC_FIDELITY_BASE_ID, DC_FIDELITY_MEMBER_THE_END)

#endif // !DC_FIDELITY_CONFIG




