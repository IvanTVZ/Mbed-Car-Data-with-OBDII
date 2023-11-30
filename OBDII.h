#ifndef OBDII_H
#define OBDII_H

#define CAN_SPEED_125k    125000    // CAN speed at 125 [kbps]
#define CAN_SPEED_250k   250000     // CAN speed at 250 [kbps]
#define CAN_SPEED_500k   500000     // CAN speed at 500 [kbps]
#define CAN_TIMEOUT      22         // CAN Timeout [us]

#define PID_REQUEST_ALL     0x7DF   // PID request all
#define PID_REQUEST         0x7E0   // PID request
#define PID_REQUEST_ECU2    0x7E1   // PID request ECU2
#define PID_REPLY           0x7E8   // PID reply
#define PID_REPLY_ECU2      0x7E9   // PID reply ECU2

/* Details: http://en.wikipedia.org/wiki/OBD-II_PIDs */
// Services / Modes
#define SERVICE_01          0x01    // Show current data
#define SERVICE_02          0x02    // Show freeze frame data
#define SERVICE_03          0x03    // Show stored Diagnostic Trouble Codes
#define SERVICE_04          0x04    // Clear Diagnostic Trouble Codes and stored values
#define SERVICE_05          0x05    // Test results, oxygen sensor monitoring (non CAN only)
#define SERVICE_06          0x06    // Test results, other component/system monitoring (Test results, oxygen sensor monitoring for CAN only)
#define SERVICE_07          0x07    // Show pending Diagnostic Trouble Codes (detected during current or last driving cycle)
#define SERVICE_08          0x08    // Control operation of on-board component/system
#define SERVICE_09          0x09    // Request vehicle information
#define SERVICE_0A          0x0A    // Permanent Diagnostic Trouble Codes (DTCs) (Cleared DTCs)

// Service 01 - Show current data
#define PID_0_20            0x00    // PIDs 0 - 20 supported
#define STATUS_DTC          0x01    // Monitor status since DTCs cleared. (Includes malfunction indicator lamp (MIL), status and number of DTCs, components tests, DTC readiness checks)
#define FREEZE_DTC          0x02    // DTC that caused freeze frame to be stored.
#define FUEL_SYS_STATUS     0x03    // Fuel system status
#define ENGINE_LOAD         0x04    // Calculated engine load
#define ENGINE_COOLANT_TEMP 0x05    // Engine coolant temperature
#define ST_FUEL_TRIM_1      0x06    // Short term fuel trim (STFT)—Bank 1
#define LT_FUEL_TRIM_1      0x07    // Long term fuel trim (LTFT)—Bank 1
#define ST_FUEL_TRIM_2      0x08    // Short term fuel trim (STFT)—Bank 2
#define LT_FUEL_TRIM_2      0x09    // Long term fuel trim (LTFT)—Bank 2
#define FUEL_PRESSURE       0x0A    // Fuel pressure (gauge pressure)
#define INTAKE_PRESSURE     0x0B    // Intake manifold absolute pressure
#define ENGINE_SPEED        0x0C    // Engine speed
#define VEHICLE_SPEED       0x0D    // Vehicle speed
#define TIMING_ADVANCE      0x0E    // Timing advance
#define INTAKE_TEMP         0x0F    // Intake air temperature
#define MAF_SENSOR          0x10    // Mass air flow sensor (MAF) air flow rate
#define THROTTLE            0x11    // Throttle position
#define COMMANDED_SEC_AIR   0x12    // Commanded secondary air status
#define O2_SENS_PRES        0x13    // Oxygen sensors present (in 2 banks)
#define O2_B1S1_VOLTAGE     0x14    // Oxygen Sensor 1
#define O2_B1S2_VOLTAGE     0x15    // Oxygen Sensor 2
#define O2_B1S3_VOLTAGE     0x16    // Oxygen Sensor 3
#define O2_B1S4_VOLTAGE     0x17    // Oxygen Sensor 4
#define O2_B2S1_VOLTAGE     0x18    // Oxygen Sensor 5
#define O2_B2S2_VOLTAGE     0x19    // Oxygen Sensor 6
#define O2_B2S3_VOLTAGE     0x1A    // Oxygen Sensor 7
#define O2_B2S4_VOLTAGE     0x1B    // Oxygen Sensor 8
#define OBDII_STANDARDS     0x1C    // OBD standards this vehicle conforms to
#define O2_SENS_PRES_ALT    0x1D    // Oxygen sensors present (in 4 banks)
#define AUX_IN_STATUS       0x1E    // Auxiliary input status
#define ENGINE_RUNTIME      0x1F    // Run time since engine start
#define PID_21_40           0x20    // PIDs 21 - 40 supported
#define DIST_TRAVELED_MIL   0x21    // Distance traveled with malfunction indicator lamp (MIL) on
#define FUEL_RAIL_PRESSURE  0x22    // Fuel Rail Pressure (relative to manifold vacuum)
#define FUEL_RAIL_PRES_ALT  0x23    // Fuel Rail Gauge Pressure (diesel, or gasoline direct injection)
#define O2S1_WR_LAMBDA_V    0x24    // Oxygen Sensor 1
#define O2S2_WR_LAMBDA_V    0x25    // Oxygen Sensor 2
#define O2S3_WR_LAMBDA_V    0x26    // Oxygen Sensor 3
#define O2S4_WR_LAMBDA_V    0x27    // Oxygen Sensor 4
#define O2S5_WR_LAMBDA_V    0x28    // Oxygen Sensor 5
#define O2S6_WR_LAMBDA_V    0x29    // Oxygen Sensor 6
#define O2S7_WR_LAMBDA_V    0x2A    // Oxygen Sensor 7
#define O2S8_WR_LAMBDA_V    0x2B    // Oxygen Sensor 8
#define COMMANDED_EGR       0x2C    // Commanded EGR
#define EGR_ERROR           0x2D    // EGR Error
#define COMMANDED_EVAP_P    0x2E    // Commanded evaporative purge
#define FUEL_LEVEL          0x2F    // Fuel Tank Level Input
#define WARMUPS_SINCE_CLR   0x30    // Warm-ups since codes cleared
#define DIST_SINCE_CLR      0x31    // Distance traveled since codes cleared
#define EVAP_PRESSURE       0x32    // Evap. System Vapor Pressure
#define BAROMETRIC_PRESSURE 0x33    // Absolute Barometric Pressure
#define O2S1_WR_LAMBDA_I    0x34    // Oxygen Sensor 1
#define O2S2_WR_LAMBDA_I    0x35    // Oxygen Sensor 2
#define O2S3_WR_LAMBDA_I    0x36    // Oxygen Sensor 3
#define O2S4_WR_LAMBDA_I    0x37    // Oxygen Sensor 4
#define O2S5_WR_LAMBDA_I    0x38    // Oxygen Sensor 5
#define O2S6_WR_LAMBDA_I    0x39    // Oxygen Sensor 6
#define O2S7_WR_LAMBDA_I    0x3A    // Oxygen Sensor 7
#define O2S8_WR_LAMBDA_I    0x3B    // Oxygen Sensor 8
#define CAT_TEMP_B1S1       0x3C    // Catalyst Temperature: Bank 1, Sensor 1
#define CAT_TEMP_B1S2       0x3E    // Catalyst Temperature: Bank 2, Sensor 1
#define CAT_TEMP_B2S1       0x3D    // Catalyst Temperature: Bank 1, Sensor 2
#define CAT_TEMP_B2S2       0x3F    // Catalyst Temperature: Bank 2, Sensor 2
#define PID_41_60           0x40    // PIDs 41 - 60 supported
#define MONITOR_STATUS      0x41    // Monitor status this drive cycle
#define ECU_VOLTAGE         0x42    // Control module voltage
#define ABSOLUTE_LOAD       0x43    // Absolute load value
#define COMMANDED_EQUIV_R   0x44    // Commanded Air-Fuel Equivalence Ratio (lambda,λ)
#define REL_THROTTLE_POS    0x45    // Relative throttle position
#define AMB_AIR_TEMP        0x46    // Ambient air temperature
#define ABS_THROTTLE_POS_B  0x47    // Absolute throttle position B
#define ABS_THROTTLE_POS_C  0x48    // Absolute throttle position C
#define ACCEL_POS_D         0x49    // Accelerator pedal position D
#define ACCEL_POS_E         0x4A    // Accelerator pedal position E
#define ACCEL_POS_F         0x4B    // Accelerator pedal position F
#define COMMANDED_THROTTLE  0x4C    // Commanded throttle actuator
#define TIME_RUN_WITH_MIL   0x4D    // Time run with MIL on
#define TIME_SINCE_CLR      0x4E    // Time since trouble codes cleared
#define MAX_R_O2_VI_PRES    0x4F    // Maximum value for Fuel–Air equivalence ratio, oxygen sensor voltage, oxygen sensor current, and intake manifold absolute pressure
#define MAX_AIRFLOW_MAF     0x50    // Maximum value for air flow rate from mass air flow sensor
#define FUEL_TYPE           0x51    // Fuel Type
#define ETHANOL_PERCENT     0x52    // Ethanol fuel %
#define ABS_EVAP_SYS_PRES   0x53    // Absolute Evap system Vapor Pressure
#define EVAP_SYS_PRES       0x54    // Evap system vapor pressure
#define ST_O2_TRIM_B1B3     0x55    // Short term secondary oxygen sensor trim, A: bank 1, B: bank 3
#define LT_O2_TRIM_B1B3     0x56    // Long term secondary oxygen sensor trim, A: bank 1, B: bank 3
#define ST_02_TRIM_B2B4     0x57    // Short term secondary oxygen sensor trim, A: bank 2, B: bank 4
#define LT_O2_TRIM_B2B4     0x58    // Long term secondary oxygen sensor trim, A: bank 2, B: bank 4
#define ABS_FUEL_RAIL_PRES  0x59    // Fuel rail absolute pressure
#define REL_ACCEL_POS       0x5A    // Relative accelerator pedal position
#define HYBRID_BATT_PCT     0x5B    // Hybrid battery pack remaining life
#define ENGINE_OIL_TEMP     0x5C    // Engine oil temperature
#define FUEL_TIMING         0x5D    // Fuel injection timing
#define FUEL_RATE           0x5E    // Engine fuel rate
#define EMISSIONS_STANDARD  0x5F    // Emission requirements to which vehicle is designed
#define PID_61_80           0x60    // PIDs 61 - 80 supported
#define DEMANDED_TORQUE     0x61    // Driver's demand engine - percent torque
#define ACTUAL_TORQUE       0x62    // Actual engine - percent torque
#define REFERENCE_TORQUE    0x63    // Engine reference torque
#define ENGINE_PCT_TORQUE   0x64    // Engine percent torque data
#define AUX_IO_SUPPORTED    0x65    // Auxiliary input / output supported
#define P_MAF_SENSOR        0x66    // Mass air flow sensor
#define P_ENGINE_COOLANT_T  0x67    // Engine coolant temperature
#define P_INTAKE_TEMP       0x68    // Intake air temperature sensor
#define P_COMMANDED_EGR     0x69    // Actual EGR, Commanded EGR, and EGR Error
#define P_COMMANDED_INTAKE  0x6A    // Commanded Diesel intake air flow control and relative intake air flow position
#define P_EGR_TEMP          0x6B    // Exhaust gas recirculation temperature
#define P_COMMANDED_THROT   0x6C    // Commanded throttle actuator control and relative throttle position
#define P_FUEL_PRESSURE     0x6D    // Fuel pressure control system
#define P_FUEL_INJ_PRES     0x6E    // Injection pressure control system
#define P_TURBO_PRESSURE    0x6F    // Turbocharger compressor inlet pressure
#define P_BOOST_PRES_CONT   0x70    // Boost pressure control
#define P_VGT_CONTROL       0x71    // Variable Geometry turbo (VGT) control
#define P_WASTEGATE_CONT    0x72    // Wastegate control
#define P_EXHAUST_PRESSURE  0x73    // Exhaust pressure
#define P_TURBO_RPM         0x74    // Turbocharger RPM
#define P_TURBO_TEMP1       0x75    // Turbocharger temperature
#define P_TURBO_TEMP2       0x76    // Turbocharger temperature
#define P_CACT              0x77    // Charge air cooler temperature (CACT)
#define P_EGT_B1            0x78    // Exhaust Gas temperature (EGT) Bank 1
#define P_EGT_B2            0x79    // Exhaust Gas temperature (EGT) Bank 2
#define P_DPF1              0x7A    // Diesel particulate filter (DPF) 1
#define P_DPF2              0x7B    // Diesel particulate filter (DPF) 2
#define P_DPF_TEMP          0x7C    // Diesel Particulate filter (DPF) temperature
#define P_NOX_NTE_STATUS    0x7D    // NOx NTE (Not-To-Exceed) control area status
#define P_PM_NTE_STATUS     0x7E    // PM NTE (Not-To-Exceed) control area status
#define P_ENGINE_RUNTUME    0x7F    // Engine run time

class OBDII {
    public:
        OBDII (int canFrequency);
        unsigned char request (unsigned char pid, bool serialEnabledFlag);
        float read (unsigned char pid, bool serialEnabledFlag);
};

#endif