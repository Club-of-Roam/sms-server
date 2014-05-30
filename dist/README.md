smsServer

NOTES:
As Symbian was discontinued, we can't get DEV certificates anymore, so,
we have to remove the enforcement of certificate checks before installing
smsServer.

PROCEDURE:
1) Install X-Plore, RP + Lite Version and NortonSymbianHackLDD.sisx in your phone. 
2) Norton started, click on Options> AntiVirus> Quarantine list (you will appear 3 files). 
   In the event that you can not access to "Quarantine list", reboot your phone and go back to point 2) 
3) Click Options> Restore All and confirm 
4) At this point you can uninstall Norton.
5) Now you can turn on the usual patch: 
   - Open4all to access the system folders. 
   - INSTALLSERVER to allow installation of unsigned. 
   If you want the patch to be applied automatically at every phone boot, then you should set it to the value       "Auto" via the options in RP +. 
6) Install smsServer.

INSTALLSERVER (RED CROSS) 
In some older models 3rd, 3rd FP1, when you try to apply the patch INSTALLSERVER you get a red cross. 
In these cases, in order to install the unsigned, you must enter in c:\sys\bin\installserver.exe an executable changed. 
The installservers_pack.zip file contains a set of modified installserver.  
- Take the most suitable one according to your model. 
- Move it to c:\sys\bin\ 
- Restart the cell. 
Now the cell. will behave as if it were perpetually installserver patch applied. 
The installation of any unsigned will always be accepted, without having to apply the patch (if applied, you will get a red cross) 
To restore the original behavior of the mobile phone, you will need to delete the file c: \ sys \ bin \ installserver.exe changed.