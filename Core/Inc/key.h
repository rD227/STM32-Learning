#ifndef __KEY_H__
#define __KEY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/**
 * @brief  读取按键状态（带消抖）
 * @param  GPIOx: GPIO端口
 * @param  GPIO_Pin: GPIO引脚
 * @retval 1: 按键按下 (高电平)
 * @retval 0: 按键未按下 (低电平)
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* __KEY_H__ */
