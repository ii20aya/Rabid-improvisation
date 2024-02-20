

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)                        reg|=(1<<bit)
#define CLEAR_BIT(reg,bit)                      reg&=(~(1<<bit))
#define TOGGLE_BIT(reg,bit)                     reg^=(1<<bit) 
#define READ_BIT(reg,bit)                              ( (reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)                    (reg&(1<<bit)>>bit)
#define IS_BIT_CLEAR(reg,bit)                  !((reg&(1<<bit)>>bit))
#define ROU_LEFT(reg,num)                      reg=(reg<<(REGISTER_SIZE-num))|(reg>>num)
#define ROU_RIGH(reg,num)                     reg=(reg>>(REGISTER_SIZE-num))|(reg<<num)






