---
layout: default
---
Smart Energy Meter
==================
*by Kanishka Rangana (18sea052)*

1 Introduction

A smart meter is an electronic device that records information such as consumption of electric energy, voltage levels and current. 
This meter is used to know how much energy has been consumed. 
The Smart meters communicate the information to the consumer for greater clarity of consumption behavior.
![Smart Meter](/Images/Finished Product/Energy Meter Front When Device ON.jpg)

2 Project Aims & Objectives

* Designing compact, rugged and cost-effective smart meter.
* Improving the accuracy of the smart meter.

3	Methodology

	3.1	Project Planning
	------------------------
		Project management is an important process. It helps to define the objectives, scope and milestones. 
		Also, the success of the project depends on proper well-defined planning and management. 
		A list of the tasks and activities that must be accomplished to reach the milestones have been 
		listed below.
 
		*	Material Selection & Cost survey
		*	Time Planning
		*	Circuit simulation and prototyping
		*	Testing & evaluation
		*	Software and hardware implementation 
		*	Debug errors and moderations
		*	Designing mechanical parts via CAD/CAM
		*	Finalizing the instrument and hand over the project
		
	3.2	Materials selection and Cost Survey
	-------------------------------------------
		3.2.1	Materials selection
		~~~~~~~~~~~~~~~~~~~~~~~~~~~
			The next most important step of this project planning is materials selection. 
			find the most suitable hardware and components for the project, the market survey is necessary
			considering usability and associated costs. 
			So as per the market survey carried out, the following items were deemed as suitable for 
			the project:

			+---------------------------------+------+-----------------------+
			|PARTS                            | Qty. |    AVAILABILITY       |
			+=================================+======+=======================+
			|Arduino NANO/UNO board           |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|ESP 8266 Node MCU Module         |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|ACS 712 Current Sensor           |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|16×2 LCD display                 |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|I2C Module                       |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|Wires                            |  N/A |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|AC 240V -  DC 9V Power Supply    |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|Screws                           |   4  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|PCB Board                        |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|Ferric Chloride Bottle           |   1  |  Available in Market  |
			+---------------------------------+------+-----------------------+
			|Plastic 3D Printed Enclosure     |   1  | Available in Market   |
			+---------------------------------+------+-----------------------+

		3.2.2	Cost Estimation
		~~~~~~~~~~~~~~~~~~~~~~~
			Cost planning establishes the baseline of the project cost at individual steps of development 
			of the project. 
			When designing a cost-effective smart meter, cost control is necessary to prevent unnecessary 
			expenses and to allocate the amount of expenditure to each requirement. 
			Following chart shows cost estimation, considering the materials selected for the project as 
			shown in section 3.2.1 which is calculated as of 2020, October.
			
			+-----------------------------+---------------+-------+
			|PARTS                        |  COST (LKR)   |  USD  |
			+=============================+===============+=======+
			|Arduino NANO/UNO board       |    890.00     | 4.78  |
			+-----------------------------+---------------+-------+
			|ESP 8266 Node MCU Module     |   1080.00     | 5.80  |
			+-----------------------------+---------------+-------+
			|ACS 712 Current Sensor       |    480.00     | 2.50  |
			+-----------------------------+---------------+-------+
			|16×2 LCD display             |    320.00     | 1.72  |
			+-----------------------------+---------------+-------+
			|I2C Module                   |    155.00     | 0.83  |
			+-----------------------------+---------------+-------+
			|Wires                        |    150.00     | 0.81  |
			+-----------------------------+---------------+-------+
			|AC 240V - DC 9V Power Supply |    400.00     | 2.15  |
			+-----------------------------+---------------+-------+
			|Screws                       |     50.00     | 0.27  |
			+-----------------------------+---------------+-------+
			|PCB Board                    |    120.00     | 0.64  |
			+-----------------------------+---------------+-------+
			|Ferric Chloride Bottle       |     70.00     | 0.38  |
			+-----------------------------+---------------+-------+
			|Plastic 3D Printed Enclosure |               |       |
			+-----------------------------+---------------+-------+
			|TOTAL                        |   3715.00     | 19.88 |
			+=============================+===============+=======+
			* (In year 2020 1 United States Dollar equals 186.10 Sri Lankan Rupee - Indicative exchange 
			rate may vary)
			
	3.3	Time Planning
	-----------------
	Scheduling is the proper way of managing project time. Managing time and progress will allow completing the 
	project on the expected deadline. 
	As per the project planning, this project is divided into three main sections such as software, hardware 
	and electronic implementation. 
	Those sections are again divided into subcategories and need to be carried out parallel to each other.
	
	Link to view Gantt Chart 
	(https://docs.google.com/spreadsheets/d/1fzoOzbvNC6VbxvWGMw2JjhFJQQX9qnlK9_MVRJGmxj8/edit?usp=sharing/)
	
	3.4	Procedure
	-------------
	This project is based on Arduino platform and Arduino-Nano board is the major component of this meter. 
	Current is measured through the ACS 712 current sensor.
	ESP8266 Wi-Fi module is used to transmit data which includes energy consumption details, to the attached 
	display via i2c module portraying real-time values & same is forwarded to log the data employing IFTTT 
	platform and MQTT dashboard enabling remote monitoring of data via an app.
