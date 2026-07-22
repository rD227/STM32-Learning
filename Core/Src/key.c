#include "key.h"

/**
 * @brief  读取按键状态（带消抖的阻塞函数）
 * @note   按键配置为下拉输入 (Pull-Down)，按下为高电平
 * @param  GPIOx: GPIO端口
 * @param  GPIO_Pin: GPIO引脚
 * @retval 1: 按键按下
 * @retval 0: 按键未按下
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    // 检测按键是否按下 (高电平)
    if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET)
    {
        // 延时消抖 (阻塞)
        HAL_Delay(20);

        // 再次检测按键状态
        if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET)
        {
            return 1; // 确认按下
        }
    }
    return 0; // 未按下
}
