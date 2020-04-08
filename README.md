The thought process behind the list is to not include the kitchen sink of ventilators out there.  One criteria for exclusion is if an Ambu bag ventilator is too costly (e.g. Umbulizer, $2k) and also has a patent dispute.  A kitchen sink for ventilator list is included at this repo: https://github.com/PubInv/covid19-vent-list - however, this repo lists a ventilator with no information, viz., http://www.pakengimed.com/ncov/.  The PubInv repo also includes the Umbulizer, but this list has excluded it as explained above.
The PubInv repo includes good info for learning ventilator.

So far a spreadsheet like comparison has not been made because many ventilators do not provide any details.  

Both MIT and Rice ventilstors use gears. Prototype gears are made out of plastic, acrylic, or aluminium which wear out sooner and won't work in production design.  I think the Virgin Orbit ventilator mechanical design does not use any gears which reduces the number of parts and makes volume production easier and faster.

# Rice University's Ambu bag ventilator

https://www.youtube.com/watch?v=oLQ5bXakWq8&feature=youtu.be

## Details
   Version 0 does not support sensor.  Uses 500 cc of air to patient.
   Device is complete with software, BOM, CAD designs, etc.
   
## Software

https://github.com/apollobvm/apollobvm


# MIT's Ambu bag ventilator

https://e-vent.mit.edu/

## Details
   Software is not complete, nor is BOM.  CAD files are complete.
   I suspect MIT is at least few weeks away to complete software,
   and documentation.

# Vanderbilt U. Ambu Bag ventilator

https://www.youtube.com/watch?v=vdLXp7uGFX4&feature=youtu.be

# Virgin Orbit's Ambu Bag ventilator

https://virginorbit.com/virgin-orbit-uci-and-ut-austin-design-new-mass-producible-ventilator-for-covid-19-patients/

Also see, https://media.wired.com/clips/5e852d038dd572000828b715/master/pass/Transpoo_Ventilatorbroll.mp4

## Details

Plans to control three key variables: breaths per minute; tidal volume, which is how much air comes out of the bag; and the inspiratory-expiratory profile, which the time spent breathing in versus breathing out. The first is a function of motor speed, adjusted with a dial. The others can be adjusted by swapping out parts. To change tidal volume, a user can hook up a smaller or larger version of the piece that pushes on the bag. The shape of the rotating cam (think of a lumpy potato versus a round one) defines how much of the time the bag is being compressed, and thus the inspiratory-expiratory rate.

# Yet Another Ambu bag ventilator with Arduino Source Code

https://github.com/ermtl/Open-Source-Ventilator

The device lists a pressure sensor part, viz., Bosch Sensortech BME280 / BMP280 sensor

Arduino source code is here in the above repo:

https://github.com/ermtl/Open-Source-Ventilator/blob/master/OpenSourceVentilator/OpenSourceVentilator.ino

# IIT Rookee and AIIMS Rishikesh ventilator

https://tinyurl.com/ur3qmd5

## Design Flaw

The device is too long.  Hospital beds are likely to be closer together and multiple devices setup will be tricky.  The device also needs wall mounts.

# IIT Kanpur incubator \(in Pune\) ventilator

https://www.youtube.com/watch?v=X9gFanQHSrE

# IIT Hyderabad incubator ventilators

## Lite version

https://www.aerobiosys.com/jeevan-lite

Looking at the device picture, I don't have a clue what pipe goes to the patient and how the device pumps air, manually or mechanically.

## ICU Version

https://www.aerobiosys.com/

# MPS with MIT e-vent

https://www.monolithicpower.com/en/mps-open-source-ventilator

# Non ICU CPAP solution from Berkeley

https://engineering.berkeley.edu/news/2020/04/turning-sleep-apnea-machines-into-ventilators/?fbclid=IwAR3OaNjvIHbSCknEq4KBEVEtKZ0Q8bVGPm7hKNCjRldSGTdFAFKj04byW-I

Also see https://www.ventilatorsos.com/our-solution.html



