EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RF_Module:ESP32-WROOM-32 U?
U 1 1 608DCA7B
P 5700 2800
F 0 "U?" H 5700 4381 50  0000 C CNN
F 1 "ESP32-WROOM-32" H 5700 4290 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 5700 1300 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 5400 2850 50  0001 C CNN
	1    5700 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_PHOTO R
U 1 1 608DD837
P 6950 2150
F 0 "R" H 7020 2196 50  0000 L CNN
F 1 "R_PHOTO" H 7020 2105 50  0000 L CNN
F 2 "" V 7000 1900 50  0001 L CNN
F 3 "~" H 6950 2100 50  0001 C CNN
	1    6950 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 608DDE97
P 6950 2600
F 0 "R1" H 7020 2646 50  0000 L CNN
F 1 "10k" H 7020 2555 50  0000 L CNN
F 2 "" V 6880 2600 50  0001 C CNN
F 3 "~" H 6950 2600 50  0001 C CNN
	1    6950 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 608DE7E2
P 7600 2600
F 0 "R2" H 7670 2646 50  0000 L CNN
F 1 "10k" H 7670 2555 50  0000 L CNN
F 2 "" V 7530 2600 50  0001 C CNN
F 3 "~" H 7600 2600 50  0001 C CNN
	1    7600 2600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Reed_Opener Anemometer
U 1 1 608E02F8
P 7600 2150
F 0 "Anemometer" V 7554 2235 50  0000 L CNN
F 1 "SW" V 7645 2235 50  0000 L CNN
F 2 "" H 7600 2150 50  0001 C CNN
F 3 "~" H 7600 2150 50  0001 C CNN
	1    7600 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	5700 4200 7250 4200
Wire Wire Line
	6950 2750 6950 3000
Wire Wire Line
	6950 3000 7250 3000
Wire Wire Line
	7600 3000 7600 2750
Wire Wire Line
	7250 4200 7250 3000
Connection ~ 7250 3000
Wire Wire Line
	7250 3000 7600 3000
Wire Wire Line
	7600 2450 7600 2400
Wire Wire Line
	6950 2450 6950 2350
Wire Wire Line
	5700 1400 7250 1400
Wire Wire Line
	7250 1400 7250 1850
Wire Wire Line
	7250 1850 6950 1850
Wire Wire Line
	6950 1850 6950 2000
Wire Wire Line
	7250 1850 7600 1850
Wire Wire Line
	7600 1850 7600 1950
Connection ~ 7250 1850
Wire Wire Line
	7600 2400 6650 2400
Wire Wire Line
	6650 2400 6650 3200
Wire Wire Line
	6650 3200 6300 3200
Connection ~ 7600 2400
Wire Wire Line
	7600 2400 7600 2350
Wire Wire Line
	6950 2350 6500 2350
Wire Wire Line
	6500 2350 6500 3700
Wire Wire Line
	6500 3700 6300 3700
Connection ~ 6950 2350
Wire Wire Line
	6950 2350 6950 2300
$EndSCHEMATC
