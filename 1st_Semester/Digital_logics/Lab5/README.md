# Lab 5

## OBJECTIVE

TO VERIFY TRUTH TABLE OF ENCODER AND DECODER VIA SIMULATOR

## APPARATUS REQUIRED

Simulator

## BLOCK DIAGRAM OF 8-TO-3 LINE BINARY ENCODER AND 3-T0-6 LINE DECODER

![8 to 3 line encoder](images/encoder.png)
![3 to 8 line decoder](images/decoder.png)

## CIRCUIT DIAGRAM OF 8-TO-3 LINE BINARY ENCODER

![8 to 3 Line binary encoder](images/circuit_diagram_encoder.png)

## TRUTH TABLE OF 8-TO-3 LINE BINARY ENCODER

| I0  | I1  | I2  | I3  | I4  | I5  | I6  | I7  | O0  | O1  | O2  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 0   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 1   |
| 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 1   | 0   |
| 0   | 0   | 0   | 1   | 0   | 0   | 0   | 0   | 0   | 1   | 1   |
| 0   | 0   | 0   | 0   | 1   | 0   | 0   | 0   | 1   | 0   | 0   |
| 0   | 0   | 0   | 0   | 0   | 1   | 0   | 0   | 1   | 0   | 1   |
| 0   | 0   | 0   | 0   | 0   | 0   | 1   | 0   | 1   | 1   | 0   |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 1   | 1   | 1   | 1   |

## CIRCUIT DIAGRAM OF 3-TO-8 LINE BINARY DECODER

![3 to 8 Line binary decoder](images/circuit_diagram_decoder.png)

## TRUTH TABLE OF 3-TO-8 LINE BINARY DECODER

| Inputs |     |     | Outputs |     |     |     |     |     |     |     |
| ------ | --- | --- | ------- | --- | --- | --- | --- | --- | --- | --- |
| X      | Y   | Z   | D0      | D1  | D2  | D3  | D4  | D5  | D6  | D7  |
| 0      | 0   | 0   | 1       | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 0      | 0   | 1   | 0       | 1   | 0   | 0   | 0   | 0   | 0   | 0   |
| 0      | 1   | 0   | 0       | 0   | 1   | 0   | 0   | 0   | 0   | 0   |
| 0      | 1   | 1   | 0       | 0   | 0   | 1   | 0   | 0   | 0   | 0   |
| 1      | 0   | 0   | 0       | 0   | 0   | 0   | 1   | 0   | 0   | 0   |
| 1      | 0   | 1   | 0       | 0   | 0   | 0   | 0   | 1   | 0   | 0   |
| 1      | 1   | 0   | 0       | 0   | 0   | 0   | 0   | 0   | 1   | 0   |
| 1      | 1   | 1   | 0       | 0   | 0   | 0   | 0   | 0   | 0   | 1   |

## Simulator Image for Encoder

![Sim Encoder](images/sim_encoder.jpg)

## Simulator Image for Decoder

![Sim Decoder](images/sim_decoder.jpg)

## RESULT

The truth table of Encoder and Decoder is verified successfully.
