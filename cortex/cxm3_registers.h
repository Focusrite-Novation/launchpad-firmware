#ifndef __CX_REGISTERS_H
#define __CX_REGISTERS_H

//////////////////////////////////////////////////////////////////////////
// Copyright 2013 Focusrite Audio Engineering Ltd.
//////////////////////////////////////////////////////////////////////////
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// (1) Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in
// the documentation and/or other materials provided with the
// distribution.
//
// (3)The name of the author may not be used to
// endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//////////////////////////////////////////////////////////////////////////

// ____________________________________________________________________________
//
// TIM1 :: advanced timer
// ____________________________________________________________________________
//

#define TIM1 0x40012C00
#define TIM1_CR1   (TIM1+0x00)
#define TIM1_CR2   (TIM1+0x04)
#define TIM1_SMCR  (TIM1+0x08)
#define TIM1_DIER  (TIM1+0x0C)
#define TIM1_SR    (TIM1+0x10)
#define TIM1_EGR   (TIM1+0x14)
#define TIM1_CCMR1 (TIM1+0x18)
#define TIM1_CCMR2 (TIM1+0x1C)
#define TIM1_CCER  (TIM1+0x20)
#define TIM1_CNT   (TIM1+0x24)
#define TIM1_PSC   (TIM1+0x28)
#define TIM1_ARR   (TIM1+0x2C)
#define TIM1_RCR   (TIM1+0x30)
#define TIM1_CCR1  (TIM1+0x34)
#define TIM1_CCR2  (TIM1+0x38)
#define TIM1_CCR3  (TIM1+0x3C)
#define TIM1_CCR4  (TIM1+0x40)
#define TIM1_BDTR  (TIM1+0x44)
#define TIM1_DCR   (TIM1+0x48)
#define TIM1_DMAR  (TIM1+0x4C)


// ____________________________________________________________________________
//
// TIM2 :: general-purpose timer
// ____________________________________________________________________________
//

#define TIM2 0x40000000
#define TIM2_CR1   (TIM2+0x00)
#define TIM2_CR2   (TIM2+0x04)
#define TIM2_SMCR  (TIM2+0x08)
#define TIM2_DIER  (TIM2+0x0C)
#define TIM2_SR    (TIM2+0x10)
#define TIM2_EGR   (TIM2+0x14)
#define TIM2_CCMR1 (TIM2+0x18)
#define TIM2_CCMR2 (TIM2+0x1C)
#define TIM2_CCER  (TIM2+0x20)
#define TIM2_CNT   (TIM2+0x24)
#define TIM2_PSC   (TIM2+0x28)
#define TIM2_ARR   (TIM2+0x2C)
#define TIM2_CCR1  (TIM2+0x34)
#define TIM2_CCR2  (TIM2+0x38)
#define TIM2_CCR3  (TIM2+0x3C)
#define TIM2_CCR4  (TIM2+0x40)
#define TIM2_DCR   (TIM2+0x48)
#define TIM2_DMAR  (TIM2+0x4C)


// ____________________________________________________________________________
//
// TIM3 :: general-purpose timer
// ____________________________________________________________________________
//

#define TIM3 0x40000400
#define TIM3_CR1   (TIM3+0x00)
#define TIM3_CR2   (TIM3+0x04)
#define TIM3_SMCR  (TIM3+0x08)
#define TIM3_DIER  (TIM3+0x0C)
#define TIM3_SR    (TIM3+0x10)
#define TIM3_EGR   (TIM3+0x14)
#define TIM3_CCMR1 (TIM3+0x18)
#define TIM3_CCMR2 (TIM3+0x1C)
#define TIM3_CCER  (TIM3+0x20)
#define TIM3_CNT   (TIM3+0x24)
#define TIM3_PSC   (TIM3+0x28)
#define TIM3_ARR   (TIM3+0x2C)
#define TIM3_CCR1  (TIM3+0x34)
#define TIM3_CCR2  (TIM3+0x38)
#define TIM3_CCR3  (TIM3+0x3C)
#define TIM3_CCR4  (TIM3+0x40)
#define TIM3_DCR   (TIM3+0x48)
#define TIM3_DMAR  (TIM3+0x4C)


// ____________________________________________________________________________
//
// TIM4 :: general-purpose timer
// ____________________________________________________________________________
//

#define TIM4 0x40000800
#define TIM4_CR1   (TIM4+0x00)
#define TIM4_CR2   (TIM4+0x04)
#define TIM4_SMCR  (TIM4+0x08)
#define TIM4_DIER  (TIM4+0x0C)
#define TIM4_SR    (TIM4+0x10)
#define TIM4_EGR   (TIM4+0x14)
#define TIM4_CCMR1 (TIM4+0x18)
#define TIM4_CCMR2 (TIM4+0x1C)
#define TIM4_CCER  (TIM4+0x20)
#define TIM4_CNT   (TIM4+0x24)
#define TIM4_PSC   (TIM4+0x28)
#define TIM4_ARR   (TIM4+0x2C)
#define TIM4_CCR1  (TIM4+0x34)
#define TIM4_CCR2  (TIM4+0x38)
#define TIM4_CCR3  (TIM4+0x3C)
#define TIM4_CCR4  (TIM4+0x40)
#define TIM4_DCR   (TIM4+0x48)
#define TIM4_DMAR  (TIM4+0x4C)


// ____________________________________________________________________________
//
// TIM5 :: general-purpose timer
// ____________________________________________________________________________
//

#define TIM5 0x40000C00
#define TIM5_CR1   (TIM5+0x00)
#define TIM5_CR2   (TIM5+0x04)
#define TIM5_SMCR  (TIM5+0x08)
#define TIM5_DIER  (TIM5+0x0C)
#define TIM5_SR    (TIM5+0x10)
#define TIM5_EGR   (TIM5+0x14)
#define TIM5_CCMR1 (TIM5+0x18)
#define TIM5_CCMR2 (TIM5+0x1C)
#define TIM5_CCER  (TIM5+0x20)
#define TIM5_CNT   (TIM5+0x24)
#define TIM5_PSC   (TIM5+0x28)
#define TIM5_ARR   (TIM5+0x2C)
#define TIM5_CCR1  (TIM5+0x34)
#define TIM5_CCR2  (TIM5+0x38)
#define TIM5_CCR3  (TIM5+0x3C)
#define TIM5_CCR4  (TIM5+0x40)
#define TIM5_DCR   (TIM5+0x48)
#define TIM5_DMAR  (TIM5+0x4C)


// ____________________________________________________________________________
//
// TIM6 :: basic timer
// ____________________________________________________________________________
//

#define TIM6 0x40001000
#define TIM6_CR1   (TIM6+0x00)
#define TIM6_CR2   (TIM6+0x04)
#define TIM6_DIER  (TIM6+0x0C)
#define TIM6_SR    (TIM6+0x10)
#define TIM6_EGR   (TIM6+0x14)
#define TIM6_CNT   (TIM6+0x24)
#define TIM6_PSC   (TIM6+0x28)
#define TIM6_ARR   (TIM6+0x2C)


// ____________________________________________________________________________
//
// TIM7 :: basic timer
// ____________________________________________________________________________
//

#define TIM7 0x40001400
#define TIM7_CR1   (TIM7+0x00)
#define TIM7_CR2   (TIM7+0x04)
#define TIM7_DIER  (TIM7+0x0C)
#define TIM7_SR    (TIM7+0x10)
#define TIM7_EGR   (TIM7+0x14)
#define TIM7_CNT   (TIM7+0x24)
#define TIM7_PSC   (TIM7+0x28)
#define TIM7_ARR   (TIM7+0x2C)


// ____________________________________________________________________________
//
// TIM8 :: advanced timer
// ____________________________________________________________________________
//

#define TIM8 0x40013400
#define TIM8_CR1   (TIM8+0x00)
#define TIM8_CR2   (TIM8+0x04)
#define TIM8_SMCR  (TIM8+0x08)
#define TIM8_DIER  (TIM8+0x0C)
#define TIM8_SR    (TIM8+0x10)
#define TIM8_EGR   (TIM8+0x14)
#define TIM8_CCMR1 (TIM8+0x18)
#define TIM8_CCMR2 (TIM8+0x1C)
#define TIM8_CCER  (TIM8+0x20)
#define TIM8_CNT   (TIM8+0x24)
#define TIM8_PSC   (TIM8+0x28)
#define TIM8_ARR   (TIM8+0x2C)
#define TIM8_RCR   (TIM8+0x30)
#define TIM8_CCR1  (TIM8+0x34)
#define TIM8_CCR2  (TIM8+0x38)
#define TIM8_CCR3  (TIM8+0x3C)
#define TIM8_CCR4  (TIM8+0x40)
#define TIM8_BDTR  (TIM8+0x44)
#define TIM8_DCR   (TIM8+0x48)
#define TIM8_DMAR  (TIM8+0x4C)


// ____________________________________________________________________________
//
// DMA1 :: direct memory access controller
// ____________________________________________________________________________
//

#define DMA1 0x40020000
#define DMA1_ISR    (DMA1+0x00)
#define DMA1_IFCR   (DMA1+0x04)
#define DMA1_CCR1   (DMA1+0x08)
#define DMA1_CNDTR1 (DMA1+0x0C)
#define DMA1_CPAR1  (DMA1+0x10)
#define DMA1_CMAR1  (DMA1+0x14)
#define DMA1_CCR2   (DMA1+0x1C)
#define DMA1_CNDTR2 (DMA1+0x20)
#define DMA1_CPAR2  (DMA1+0x24)
#define DMA1_CMAR2  (DMA1+0x28)
#define DMA1_CCR3   (DMA1+0x30)
#define DMA1_CNDTR3 (DMA1+0x34)
#define DMA1_CPAR3  (DMA1+0x38)
#define DMA1_CMAR3  (DMA1+0x3C)
#define DMA1_CCR4   (DMA1+0x44)
#define DMA1_CNDTR4 (DMA1+0x48)
#define DMA1_CPAR4  (DMA1+0x4C)
#define DMA1_CMAR4  (DMA1+0x50)
#define DMA1_CCR5   (DMA1+0x58)
#define DMA1_CNDTR5 (DMA1+0x5C)
#define DMA1_CPAR5  (DMA1+0x60)
#define DMA1_CMAR5  (DMA1+0x64)
#define DMA1_CCR6   (DMA1+0x6C)
#define DMA1_CNDTR6 (DMA1+0x70)
#define DMA1_CPAR6  (DMA1+0x74)
#define DMA1_CMAR6  (DMA1+0x78)
#define DMA1_CCR7   (DMA1+0x80)
#define DMA1_CNDTR7 (DMA1+0x84)
#define DMA1_CPAR7  (DMA1+0x88)
#define DMA1_CMAR7  (DMA1+0x8C)

// ____________________________________________________________________________
//
// PWR :: power control
// ____________________________________________________________________________
//

#define PWR 0x40007000
#define PWR_CR      (PWR+0x00)
#define PWR_CSR     (PWR+0x04)

// ____________________________________________________________________________
//
// BKP :: battery backup RAM
// ____________________________________________________________________________
//

#define BKP 0x40006C00
#define BKP_DR1     (BKP+0x04)
#define BKP_DR2     (BKP+0x08)
#define BKP_DR3     (BKP+0x0C)
#define BKP_DR4     (BKP+0x10)

// ____________________________________________________________________________
//
// AFIO :: alternative function I/O
// ____________________________________________________________________________
//

#define AFIO 0x40010000
#define AFIO_MAPR	(AFIO+0x04)

// ____________________________________________________________________________
//
// GPIO A :: general purpose I/O interface A
// ____________________________________________________________________________
//

#define GPIOA 0x40010800
#define GPIOA_CRL (GPIOA)
#define GPIOA_CRH (GPIOA+0x4)
#define GPIOA_IDR (GPIOA+0x8)
#define GPIOA_ODR (GPIOA+0xC)
#define GPIOA_BSRR (GPIOA+0x10)

// ____________________________________________________________________________
//
// GPIO B :: general purpose I/O interface B
// ____________________________________________________________________________
//

#define GPIOB 0x40010C00
#define GPIOB_CRL (GPIOB)
#define GPIOB_CRH (GPIOB+0x4)
#define GPIOB_IDR (GPIOB+0x8)
#define GPIOB_ODR (GPIOB+0xC)
#define GPIOB_BSRR (GPIOB+0x10)

// ____________________________________________________________________________
//
// GPIO C :: general purpose I/O interface C
// ____________________________________________________________________________
//

#define GPIOC 0x40011000
#define GPIOC_CRL (GPIOC)
#define GPIOC_CRH (GPIOC+0x4)
#define GPIOC_IDR (GPIOC+0x8)
#define GPIOC_ODR (GPIOC+0xC)
#define GPIOC_BSRR (GPIOC+0x10)

// ____________________________________________________________________________
//
// GPIO D :: general purpose I/O interface D
// ____________________________________________________________________________
//

#define GPIOD 0x40011400
#define GPIOD_CRL (GPIOD)
#define GPIOD_CRH (GPIOD+0x4)
#define GPIOD_IDR (GPIOD+0x8)
#define GPIOD_ODR (GPIOD+0xC)
#define GPIOD_BSRR (GPIOD+0x10)

// ____________________________________________________________________________
//
// GPIO E :: general purpose I/O interface E
// ____________________________________________________________________________
//

#define GPIOE 0x40011800
#define GPIOE_CRL (GPIOE)
#define GPIOE_CRH (GPIOE+0x4)
#define GPIOE_IDR (GPIOE+0x8)
#define GPIOE_ODR (GPIOE+0xC)
#define GPIOE_BSRR (GPIOE+0x10)

// ____________________________________________________________________________
//
// ADC 1 : analogue-to-digital converter 1
// ____________________________________________________________________________
//

#define ADC1 0x40012400
#define ADC1_SR    (ADC1+0x00)
#define ADC1_CR1   (ADC1+0x04)
#define ADC1_CR2   (ADC1+0x08)
#define ADC1_SMPR1 (ADC1+0x0C)
#define ADC1_SMPR2 (ADC1+0x10)
#define ADC1_SQR1  (ADC1+0x2C)
#define ADC1_SQR2  (ADC1+0x30)
#define ADC1_SQR3  (ADC1+0x34)
#define ADC1_DR    (ADC1+0x4C)

// ____________________________________________________________________________
//
// DAC : digital-to-analogue converter
// ____________________________________________________________________________
//

#define DAC 0x40007400
#define DAC_CR      (DAC+0x00)
#define DAC_SWTRIGR (DAC+0x04)
#define DAC_DHR12R1 (DAC+0x08)
#define DAC_DHR12L1 (DAC+0x0C)
#define DAC_DHR8R1  (DAC+0x10)
#define DAC_DHR12R2 (DAC+0x14)
#define DAC_DHR12L2 (DAC+0x18)
#define DAC_DHR8R2  (DAC+0x1C)
#define DAC_DHR12RD (DAC+0x20)
#define DAC_DHR12LD (DAC+0x24)
#define DAC_DHR8RD  (DAC+0x28)
#define DAC_DOR1    (DAC+0x2C)
#define DAC_DOR2    (DAC+0x30)


// ____________________________________________________________________________
//
// SPI 1 : serial peripheral interface 1
// ____________________________________________________________________________
//

#define SPI1 0x40013000
#define SPI1_CR1 (SPI1+0x00)
#define SPI1_CR2 (SPI1+0x04)
#define SPI1_SR (SPI1+0x08)
#define SPI1_DR (SPI1+0x0C)

// ____________________________________________________________________________
//
// SPI 2 : serial peripheral interface 2
// ____________________________________________________________________________
//

#define SPI2 0x40003800
#define SPI2_CR1 (SPI2+0x00)
#define SPI2_CR2 (SPI2+0x04)
#define SPI2_SR (SPI2+0x08)
#define SPI2_DR (SPI2+0x0C)
#define SPI2_I2SCFGR (SPI2+0x1C)

// ____________________________________________________________________________
//
// I2C 1 :: inter-integrated circuit interface 1
// ____________________________________________________________________________
//

#define I2C1 0x40005400
#define I2C1_CR1   (I2C1+0x00)
#define I2C1_CR2   (I2C1+0x04)
#define I2C1_OAR1  (I2C1+0x08)
#define I2C1_OAR2  (I2C1+0x0C)
#define I2C1_DR    (I2C1+0x10)
#define I2C1_SR1   (I2C1+0x14)
#define I2C1_SR2   (I2C1+0x18)
#define I2C1_CCR   (I2C1+0x1C)
#define I2C1_TRISE (I2C1+0x20)

// ____________________________________________________________________________
//
// RCC :: reset and clock control
// ____________________________________________________________________________
//

#define RCC 0x40021000
#define RCC_CR       (RCC+0x00)
#define RCC_CFGR     (RCC+0x04)
#define RCC_APB2RSTR (RCC+0x0C)
#define RCC_APB1RSTR (RCC+0x10)
#define RCC_AHBENR   (RCC+0x14)
#define RCC_APB2ENR  (RCC+0x18)
#define RCC_APB1ENR  (RCC+0x1C)


// ____________________________________________________________________________
//
// FLASH :: FLASH memory control
// ____________________________________________________________________________
//

#define FLASH			0x40022000
#define	FLASH_ACR		(FLASH+0x00)
#define	FLASH_KEYR		(FLASH+0x04)
#define	FLASH_OPTKEYR	(FLASH+0x08)
#define	FLASH_SR		(FLASH+0x0C)
#define FLASH_CR		(FLASH+0x10)
#define FLASH_AR		(FLASH+0x14)
#define FLASH_OBR		(FLASH+0x1C)
#define FLASH_WRPR		(FLASH+0x20)


// ____________________________________________________________________________
//
// USB :: USB
// ____________________________________________________________________________
//

#define USB 0x40005C00
#define USB_CNTR (USB+0x40)
#define USB_ISTR (USB+0x44)
#define USB_FNR (USB+0x48)
#define USB_DADDR (USB+0x4C)
#define USB_BTABLE (USB+0x50)

#define USB_EP0R (USB+0x00)
#define USB_EP1R (USB+0x04)
#define USB_EP2R (USB+0x08)
#define USB_EP3R (USB+0x0C)
#define USB_EP4R (USB+0x10)
#define USB_EP5R (USB+0x14)
#define USB_EP6R (USB+0x18)
#define USB_EP7R (USB+0x1C)

#define USB_SRAM 0x40006000

// ____________________________________________________________________________
//
// USART 2
// ____________________________________________________________________________
//

#define USART2 0x40004400
#define USART2_SR   (USART2+0x00)
#define USART2_DR   (USART2+0x04)
#define USART2_BRR  (USART2+0x08)
#define USART2_CR1  (USART2+0x0C)
#define USART2_CR2  (USART2+0x10)
#define USART2_CR3  (USART2+0x14)
#define USART2_GTPR (USART2+0x18)

// ____________________________________________________________________________
//
// USART 3
// ____________________________________________________________________________
//

#define USART3 0x40004800
#define USART3_SR   (USART3+0x00)
#define USART3_DR   (USART3+0x04)
#define USART3_BRR  (USART3+0x08)
#define USART3_CR1  (USART3+0x0C)
#define USART3_CR2  (USART3+0x10)
#define USART3_CR3  (USART3+0x14)
#define USART3_GTPR (USART3+0x18)

// ____________________________________________________________________________
//
// UART 4
// ____________________________________________________________________________
//

#define UART4 0x40004C00
#define UART4_SR   (UART4+0x00)
#define UART4_DR   (UART4+0x04)
#define UART4_BRR  (UART4+0x08)
#define UART4_CR1  (UART4+0x0C)
#define UART4_CR2  (UART4+0x10)
#define UART4_CR3  (UART4+0x14)
#define UART4_GTPR (UART4+0x18)


// ____________________________________________________________________________
//
// NVIC :: Nested Vector Interrupt Controller
// These addresses are in the ARM Cortex-M3 Technical Reference Manual
// and in ST's own PM0056.
// ____________________________________________________________________________
//

#define NVIC 0xE000E100
#define NVIC_ISR (NVIC+0x000)
#define NVIC_ICR (NVIC+0x080)
#define NVIC_SETPEND (NVIC+0x100)
#define NVIC_CLRPEND (NVIC+0x180)
#define NVIC_PRIORITY (NVIC+0x300)

// ____________________________________________________________________________
//
// SCB :: System Control Block
// These addresses are in the ARM Cortex-M3 Technical Reference Manual
// and in ST's own PM0056.
// ____________________________________________________________________________
//

#define SCB 0xE000ED00
#define SCB_VTOR	(SCB+0x08)
#define SCB_AIRCR   (SCB+0x0C)

#endif
