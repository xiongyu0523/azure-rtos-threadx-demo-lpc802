/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "pin_mux.h"
#include "tx_api.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_PORT BOARD_USER_LED_PORT
#define BOARD_LED_PIN BOARD_USER_LED_PIN

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#define DEMO_STACK_SIZE		256

/*******************************************************************************
 * Variables
 ******************************************************************************/
TX_THREAD   thread_0;
uint32_t    thread_0_stack[DEMO_STACK_SIZE / sizeof(uint32_t)];

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief thread 0 entry
 */
void thread_0_entry(ULONG thread_input)
{
	(void)thread_input;

    while(1) {
        tx_thread_sleep(100);
        GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN);
    }
}


/*!
 * @brief User defined initialization function
 */
void tx_application_define(void *first_unused_memory)
{
	(void)first_unused_memory;

	(void)tx_thread_create(&thread_0, "thread 0", thread_0_entry, (ULONG)0,
                           &thread_0_stack[0], DEMO_STACK_SIZE, 1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);
}


/*!
 * @brief Main function
 */
int main(void)
{
    /* hw init */
    GPIO_PortInit(GPIO, BOARD_LED_PORT);
    CLOCK_Select(kUART0_Clk_From_MainClk);
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    tx_kernel_enter();
    return -1;
}
