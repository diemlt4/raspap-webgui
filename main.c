#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void stopWpa()
{
   system("sudo pkill -f wpa_supplicant");
}
void createCfgFile(char *ssid, char *pass)
{
 system("sudo chmod 666 wpa.conf");
 system("echo \"ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\" > wpa.conf");
 system("echo \"update_config=1\" >> wpa.conf");
 system("echo \"country=US\r\n\" >> wpa.conf");
  char buf[100];
sprintf(buf, "sudo wpa_passphrase %s %s >> wpa.conf", ssid, pass);
printf("buf is %s\r\n", buf);
 system(buf);

  
}
void startWpa()
{
   system("sudo wpa_supplicant -Dnl80211,wext -iwlan0 -cwpa.conf &");
}
void main()
{
  stopWpa();
  sleep(1);
  createCfgFile("Samsung2", "123456789");
 startWpa();
}
