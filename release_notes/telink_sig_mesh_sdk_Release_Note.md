## V3.2.3
### Bug Fixes

* (Firmware) fix bug: node can't send mesh commands during GATT OTA.
* (IOS APP) fix bug: app can't judge that have read the att_service table completely, if there is no characteristic value in the last att_service.
* (IOS APP) fix bug: only report “responseMax” packets to application layer when the number of packets received is bigger than "responseMax".

### Features	

* (Firmware) gateway can send adv packets and can be connected by master. enable PROVISIONER_GATT_ADV_EN for this function, disabled by default.
* (Firmware) the number of ota nodes is expanded to 200 in gateway project, which is defined by MESH_OTA_UPDATE_NODE_MAX.
* (Firmware) add UART mode for 8269 master dongle project. Master dongle firmware need set HCI_ACCESS to HCI_USE_UART, and sig_mesh_tool.exe need select the "UART" button to enable this function. The default is USB mode.
* (Firmware) add customized functions for TangSeng.(update latest customer's protocol)
* (Firmware) add customized functions for PiPa.
* (android APP) add API of connecting specified node and reporting the connection status to app.
* (android APP) add the function of displaying and comparing the PID value before OTA.
* (IOS APP) add the function of adding new NetKey and AppKey, and app can use the new key to send commands.

### Performance Improvements

* (Firmware) Improve compatibility by removing the association between the transmit interval and the connection interval, when the node is in GATT connected state.
* (Firmware) Improve HSL transition algorithm.

### BREAKING CHANGES

* N/A

### Notes

* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.


### Bug Fixes

* (Firmware) 修复节点在进行 GATT OTA 的时候，不能发送 mesh 命令的问题。
* (IOS APP) 修复如果设备最后一个服务内没有特征值时，无法判断出读取服务列表完毕的问题。
* (IOS APP) 修复当命令的实际回包数量大于"responseMax"时，只上报了responseMax个回包到应用层的问题。

### Features

* (Firmware) 增加gateway节点发送可连接广播包和被master连接的功能。把PROVISIONER_GATT_ADV_EN置为1可开启这个功能，默认为0.
* (Firmware) gateway 进行mesh OTA的节点数增加到200个节点, 具体数量定义是MESH_OTA_UPDATE_NODE_MAX。
* (Firmware) 增加8269 master dongle的串口通讯模式。 master dongle firmware配置HCI_ACCESS为HCI_USE_UART，上位机选择 "UART"按钮即可。默认为USB模式。
* (Firmware) 增加tangseng客户的定制功能（更新最新接入协议）。
* (Firmware) 增加PiPa客户的定制功能。
* (android APP) 增加API接口，用于连接指定节点，并且把连接状态上报给app;
* (android APP) 增加在OTA前显示和判断PID的功能;
* (IOS APP) 增加添加新的NetKey和AppKey的功能，并能使用新添加的key发送指令。

### Performance Improvements

* (Firmware) 取消直连节点的发包间隔和连接间隔的关联，提高兼容性。
* (Firmware) 改善HSL渐变算法。

### BREAKING CHANGES

* N/A

### Notes

* 为避免编译错误以及功能丢失，升级SDK时，请确认更新全部SDK文件。



## V3.2.2
### Bug Fixes

* (android APP) fix bug: provision failed(timeout) if static-oob data is not found in a static-oob device side. 
* (android APP) fix bug: app key binding failed if the target vendor model does not support app key encryption. 

### Features

* update 8278 driver for A2 chip.
* add GATT low power mode, need to enable macro of GATT_LPN_EN, disabled by default.
* add the flow of proprietary GATT_OTA login, just customization function for customer 'Pipa', need to enable macro of MESH_PIPA_ENABLE and DUAL_OTA_NEED_LOGIN_EN.
* add “user_app_config.h” for user to modify some default settings. It can be use to separate user settings and application codes from SDK.
* add customized hardware security mode and update their lib version to 1.4.1, just customization function for customer 'Tangseng'.
* (iOS APP) support static oob provisioning and static oob database importing.

### Performance Improvements

* (VC tool, APP) update storage format of json file.

### BREAKING CHANGES

* N/A

### Note

* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.


## V3.2.1
### Features
* (firmware) update 8278 drivers for A1.
* (android APP) add function of static_oob provisioning.

### Bug Fixes
* (firmware) fix a bug about ota, this bug is only in the customer's project of tangseng.

### BREAKING CHANGES

* N/A


## V3.2.0
### Bug Fixes
* fix some error characters in UART log in sometimes.
* (android APP) fix issue of multi hop command:change transition time from none to default when sending command.

### Features
* add beacon functions(iBeacon&Eddystone), disabled by default.
* enable SUBSCRIPTION_SHARE_EN as default to share group setting between the models which are in bind state.
* LPN：set LED state 'on' by default. Once power up, send level status message to display in UI. Long press key SW1 to trigger factory reset function.
* add a new macro FEATURE_FRIEND_EN,user can set FEATURE_FRIEND_EN to 0 to disable friend feature to reduce RAM and code size.
* improve user experience by letting nodes which are provisioned can be shown in GATT scan window of sig_mesh_tool.exe.
* Tangseng project: merge library of mesh1.4.0 and add vendor_publish function.
* (android APP) switch from c-lib version to java-source version.
* (android APP) add QR code to share network by cloud.
* (IOS APP) cut down the size of OpenSSL file.
* (IOS APP) add nodeIdentifySet in GATT OTA.
* (IOS APP) add sourceCode library TelinkSigMeshLib, update doc of sourceCode library TelinkSigMeshLib.

### Performance Improvements
* (android APP) optimize success rate of remote-provision
* (IOS APP) optimize success rate of remote-provision

### BREAKING CHANGES

* N/A


## V3.1.6
### Bug Fixes
* fix ttl bug:change command's ttl from 1 to 10 in android app.
### Features
* for MESH_IRONMAN_MENLO_ENABLE configuration.
    - update flash map to allow new bootloader and dual-mode image updates.
    - update mesh firmware's CLOCK from 16MHz to 32MHz.
    - add tx power calibration for constant output power.
* update bootloader firmware's CLOCK from 24MHz to 48MHz.
* add IO defines for 825x 32pin dongle.

### BREAKING CHANGES

* N/A


## V3.1.5
### Bug Fixes		
* 8269 mesh project Spirit mode(MESH_SPIRIT_ENABLE): fix compile error.	
					
### Features		
* spirit lpn project use soft timer.
* Add demo: light control model cooperate with sensor model. Code refer to SENSOR_LIGHTING_CTRL_EN.
* Set TTL default value from 5 to 10.
* Eclipse compile in multy thread mode.

### BREAKING CHANGES

* N/A


## V3.1.4
### Features
* add mesh+zb_ble dual mode
### Bug Fixes
* fw:Fixed getting vid error when enable mi/genie dual mode
* app:Fixed duplicate symbol '_crc16' issue

### BREAKING CHANGES

* N/A


## V3.1.0
### Features
* add project to support both Tmall genius and Xiaomi XiaoAI. Set MESH_USER_DEFINE_MODE to MESH_MI_SPIRIT_ENABLE. Note: must use Chip with 1M flash
* INI command：if TID value is not 0, it will be used when send command. if TID is 0, it will auto be increased by stack.
* 1M flash: add no pingpong OTA fuction.Please refer to PINGPONG_OTA_DISABLE.
* Add the model of the light mode, switch ,switch with battery for the mi mode .
* support 8278.
* Homekit and sig mesh dual mode project can self define flash map
* Lpn reserve more retention area for user.
* add dimmer ligtht/naught wire switch/live wire switch
* ios:
* 1.update lib.
* 2.Set publish of time model when app keyBind device success, period.steps are 20 seconds, time_auth is 1.
* 3.App will call statusNowTime when SDK callback setFilter success.
* 4.Optimize setFilter api.
* 5.Add SigMeshOC.framework automatic packaging script "Script.sh".
* 6.SigMeshOCDemo integrates SigMeshOC.framework by default, developer also can integrates sourceCode project "SigMeshOC.xcodeproj".
* 7.Sno will be stored locally on the mobile phone from this version, not in JSON. The local address of the provisioner is not necessarily the minimum address of the allocatedUnicastRange.
* android:
* 1. LPN node control: add on/off function;
* 3. add time publish if node contains time model when scanning and send time status when connect success;
* 4. update lib  

### BREAKING CHANGES

* N/A




