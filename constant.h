#ifndef CONSTANT_H
#define CONSTANT_H

//操作数据库回调函数错误码
#define DB_ID_ERROR                 1           //ID错误
#define DB_LEN_ERROR               2           //数据长度错误

#define     DB_RET_PTR_EERO                 -3
#define     DB_RET_EMPTY                        -2
#define     DB_RET_OTHSER_ERROR       -1
#define     DB_RET_SUCESS                       0

//定义命令码
////////////////////////////////////////////////////////////////////////////////
// 命令类型:网管与MCU之间的通信，命令格式，id--src--dst--cmd
//NM net manager  mcu 工控机 card 板卡
#define ID_NM_MCU_GET_CARD_TYPE             0x80000005
#define ID_MCU_NM_RE_CARD_TYPE               0x80000006
#define ID_MCU_NM_RE_CARD_VERSION        0x80000036
//MCU与板卡通信
#define ID_MCU_CARD_GET_DEVTYPE               0x60000000	///<工控板查询设备板卡类型信息
#define ID_CARD_MCU_RET_DEVTYPE               0x60000001	///<返回设备类型信息
#define ID_CARD_MCU_RET_OPM_ALARM          0x80000029	///<返回设备类型信息


//#define ID_CU_NOTE_NET               0x60000002///<工控板与CU通信的网段选择切换通知
//#define ID_CU_NOTE_MANAGE		0x60000003///<CU通知工控板网管的连接状态

//错误应答码
#define ID_MCU_NM_RCODE_OK                   0       //一切顺利，ok
#define ID_MCU_NM_RCODE_NO_CARD                   1       //板卡不存在
#define ID_MCU_NM_RCODE_COMMU_EROR                   2       //通信异常
#define ID_MCU_NM_RCODE_FRAME_EROR                   3       //从机号错误
#define ID_MCU_NM_RCODE_CARD_EROR                   4       //槽位号错误
#define ID_MCU_NM_RCODE_DEV_TYPE_EROR                   5       //设备类型不一致
#define ID_MCU_NM_RCODE_PARA_EROR                   6       //参数非法
#define ID_MCU_NM_RCODE_PARA_NOT_SAVE                   7       //命令参数无法保存
#define ID_MCU_NM_RCODE_CMD_EXIST                   8       //已经存在一条命令
#define ID_MCU_NM_RCODE_OTDR_EROR                   9       //测量异常
#define ID_MCU_NM_RCODE_OTDR_TIMEOUT                   10       //测量超时
#define ID_MCU_NM_RCODE_UPDATA_EROR                   11       //升级异常
#define ID_MCU_NM_RCODE_CMD_INVALIDE                   12       //无效命令


//#define ID_CMD_SMS_ERROR		27	///<RTU返回短信操作返回码

//#define ID_ALARM_MEASUR			0x80000035	//OPM告警之后的otdr测量
//#define ID_ALARM_CURV			0x80000035	///告警测量得到的曲线
//#define ID_APPOINT_MEASUR			0x80000023	// 点名测量
//#define ID_APPOINT_CURV			0x80000024	//店名测量得到的曲线

#define USR_DEBUG  1        //  如果处调试模式，将会输出调试信息，正式发布的时候，调试信息需要屏蔽

//通信故障类型
#define COMMU_STATE_CHANGE                  1

#define ALARM_HW_COMMU_OK                  0
#define ALARM_HW_COMMU_ERROR                  1
#define ALARM_HW_CARD_TYPE_UN_MATCH                 2
#define NM_LOST_JUD_TIME                    15

//光开关级联深度3，不包含接有光纤的端,比协议增加了一级冗余度
#define OSW_CONNECT_DEPTH               3
//级联的末端是otdr，开始有可能是otdr,olp,osw
#define OSW_ROUT_EQ_NUM                    OSW_CONNECT_DEPTH + 2
//查询模块路由时BUF长度
#define ROUT_BUF_LEN            OSW_CONNECT_DEPTH*2 + 1
//定义光开关的公共端口
#define COMN_COM        0xEFFFFFFF
//数据库操作
#define DB_GET_RECORD_NUM       0
#define DB_GET_RECORD                 1
//主控单元的机框，槽位
#define MCU_FRAME           0
#define MCU_CARD        NUM_COMM_CARD - 1
#define TU_CARD          MCU_CARD
//定义用户事件
#define USR_EVENT_FIND_ALARM  0

#define TSK_WILL_DEAD  1
#define TSK_NORMAL  1
#define TSK_INITIAL_NO     0
#define TSK_INITIAL_YES     1
//对某端口进行测量，首先检查该端口是否是某个关联关系中的一环，如果是，则不能进行测量
#define  PORT_CHECK     1
#define  PORT_MEASUR  0
//olp切换类型
#define OLP_SWITCH_MANUE    1    //人工切换
#define OLP_SWITCH_AUTO         2 //自动保护切换
#define OLP_SWITCH_RETURN  3    //保护返回
//板卡组成信息buf,需要根据_tagCardAttribute的size进行调整
#define CARD_COMPOSITION_SIZE   NUM_CARD*NUM_SUBRACK*32
#define SOFT_VERSON_LEN         48
//文件路径长度和文件名字长度
#define FILE_PATH_LEN       128
#define FILE_NAME_LEN       32
//电源个数
#define POWER_NUM   2
#ifdef GPIO_EDITION_12

#define CONFIG_BOARD  12
//定义GPIO口
#define GPIO_PIN_NUM            30 //IO口数目
#define PIN_IP_SET                  0       //ip段 0 192.168.1.x网段 1 192.168.0.1.x网段
#define PIN_ALARM_SILENCE       20  //告警消音按键
#define PIN_LED_ALARM_TOTAL         21  //总的告警灯，亮，表示有告警
#define PIN_LED_RUN         22                      //运行灯
#define PIN_LED_ALARM_COMM          24 //通信告警灯
#define PIN_SMS_SOFT_RESET     25   //短信软重启
#define PIN_SMS_HARD_RESET     26  //短信猫硬重启
#define PIN_SWITCH_RESET                  27    //交换机重启
#define PIN_ALARM_BUZZER                  29    //告警蜂鸣器
#else
#define CONFIG_BOARD  11
#define GPIO_PIN_NUM            27 //IO口数目
#define PIN_IP_SET                  0       //ip段 0 192.168.1.x网段 1 192.168.0.1.x网段
#define PIN_ALARM_SILENCE       20  //告警消音按键
#define PIN_LED_ALARM_TOTAL         21  //总的告警灯，亮，表示有告警
#define PIN_LED_RUN         22                      //运行灯
#define PIN_LED_ALARM_COMM          23 //通信告警灯
#define PIN_SMS_SOFT_RESET     24   //短信软重启
#define PIN_SMS_HARD_RESET     25  //短信猫硬重启
#define PIN_SWITCH_RESET                  26    //交换机重启
#define PIN_ALARM_BUZZER                  PIN_LED_ALARM_TOTAL    //告警蜂鸣器和告警灯相同
#endif

#define PIN_PW_NUM  6           //电源状态IO口数量
#define PIN_CARD_NUM           13 //MCU端口永远是插入状态，不会有拔出状态的
#define PW_STATE_NORMAL     0
#define PW_STATE_ERROR       1


//定义一个未定义错误
#define  UNDEFINED_ERROR            0x100000ff
//重启类型
#define  REBOOT_TYPE_NORMAL     0
#define  REBOOT_TYPE_ABNORMAL   1

//定义发送类型，包括查询，主动上报，重发
#define SEND_TYPE_ASK   0       //查询
#define SEND_TYPE_INITIATIVE   1 //主动上报
#define SEND_TYPE_RETRY         2 //重发
//定义告警曲线处理类型
#define ALARM_CURV_DEL                 3
//OTDR测试原因：周期性测量，光功告警测量，光功告警消失测量,OLP切换
#define TEST_CYC       0
#define TEST_OPM_ALARM_COME       1
#define TEST_OPM_ALARM_AWAY       2
#define  TEST_OLP_ACTION                   3
//告警延迟时间
#define ALARM_DELAY_TIME_S          90
//无效fd
#define INVALID_FD  0
#define branch develop
#define TMP_BRANCH
reset --hard

#endif // CONSTANT_H
