# On-Demand-Traffic-Light
embedded system project traffic light based on interrupt
# system description 
. As a pedestrian when I will make a short press on the crosswalk button while the cars 
green light is on and pedestrian red light is off, I will wait for the yellow lights to blink 
for five seconds then the cars red light is on and pedestrian green light is on for five 
seconds, so that I can cross the street
. As a pedestrian when I will make a short press on the crosswalk button while the cars 
yellow light is blinking and pedestrian red light is on, I will wait for all yellow lights to 
blink for five seconds then the cars red light is on and pedestrian green light is on for 
five seconds, so that I can cross the street
. As a pedestrian when I will make a short press on the crosswalk button while the cars red 
light is on and pedestrian green light is on, I expect nothing to be done 
. As a pedestrian when I made a long press on the crosswalk button, I expect nothing to be 
done. [as the interrupt should detect the rising on the volt only] 
. As a pedestrian when I made a double press on the crosswalk button, I expect that the first 
press will do the action and nothing to be done after the second press
