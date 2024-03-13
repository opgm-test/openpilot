# OPGM-Test openpilot fork

This is a fork of OPGM's fork of [openpilot](https://github.com/commaai/openpilot/), an open source driver assistance system. Please
consult the official documentation for most questions.

OPGM strives to align as closely to the official openpilot as possible, while adding functionality for GM vehicles that
are officially unsupported. Additionally, OPGM adds some creature comforts and quality of life improvements.

OPGM-Test is just my test version for my own personal use. I suggest you use the OPGM fork, or another fork, just not this one. This
is for my testing only. 

At the moment, the main differences are that the branches ending in 23 (build23, dev23, staging23) are hardcoded with a fingerprint for
a Chevrolet Bolt EUV 2022. Why does it end in 23 you ask? Because I have a Bolt EV 2023. Also, the registration nag has been disabled
for anyone with a clone unit. The last known working (for me) version ends in -bak, i.e. before I update the build branch, I'll back it
up as build-bak. So if I upgrade to the newest OPGM and it doesn't work, I can easily roll right back to the last knwon working version.

Now, onto the rest of the copy/paste Github included from OPGM:

## Features
* Support for GM vehicles with LKAS but no ACC
* Pedal interceptor support for longitudinal control
  * Also provides full regen on GM Bolt EV/EUV with ACC (*in process of upstreaming*)
* CC long, aka "[redneck ACC](https://www.youtube.com/watch?v=41wZ1EAmf94)" to automatically adjust nonadaptive cruise
control
  * > CC long is not a substitute for ACC. It is incapable of reducing the vehicle speed below 24mph.
* Neural network steering control, credit twilsonco
* Always On Lateral (AOL), credit pfeiferj

## Supported vehicles list
OPGM is capable of supportng vehicles on the Global A architecture that have factory LKAS. Currently supported vehicles
include:
* All vehicles supported by upstream openpilot
* 2016-2019 Chevrolet Volt
* 2017-2019 Chevrolet Bolt EV
* 2020-2023 Chevrolet Bolt EV/EUV w/o ACC
* Chevrolet Equinox/GMC Terrain w/o ACC
* Chevrolet Tahoe/GMC Yukon w/o ACC
* Chevrolet Suburban w/o ACC

If your vehicle is not on this list, there is a very good chance that already is or can be supported! You will need to
collect your vehicle's fingerprint.

> At this time, Global B and VIP architectures are unsupported due to CAN bus encryption. If you have a vehicle on one
> of these architectures and consider yourself to be a hacker/tinkerer type, we would love to hear from you!

### Fingerprinting your vehicle
Note! You likely do not have to do this. Try installing OPGM first, and only proceed with the fingerprinting process if
it does not work out of the box.

You will first need to set up [SSH access](https://github.com/commaai/openpilot/wiki/SSH) to your device. Then, follow
the fingerprinting instructions posted [here](https://github.com/commaai/openpilot/wiki/Fingerprinting#fingerprinting-10).

> You must follow the **v1.0** instructions. Fingerprint v2.0 is not yet supported for GM vehicles.

Reach out in the [OPGM discord channel](#discussion) with questions, or after you have fingerprinted your vehicle so it
can be added to OPGM.

## Installation
### Hardware
OPGM supports the Comma Three development platform; legacy support for Comma Two is not guaranteed. Some older development
branches may work on Comma Two. Use at your own risk.

Verify first that your vehicle has LKAS. Verify as well that it has a forward-facing camera; you can do this by removing
the plastic cover on the windshield behind the rearview mirror. If you see a silver rectangular camera, you're good to go.

If you have vehicle supported by upstream openpilot, buy the corresponding hardware from Comma.

If you have a vehicle without ACC, buy the [Bolt EV/EUV kit from Comma](https://comma.ai/shop/comma-three). If you have
a Bolt EV/EUV, it is **strongly** recommended to purchase a pedal interceptor for the best experience. (You may always
add one later, if you want to try OPGM before committing.)

You may buy a pedal interceptor from the following vendors:
* [TinyBear](https://www.etsy.com/listing/952895642/openpilot-comma-pedal-non-customizable?variation0=3013902165)

### Software
For the latest stable build, use the install URL: `opgm.cc`

> #### Installation troubleshooting
> If the installation fails partway through, try moving your device closer to your WiFi router.
>   * You may plug the Comma Three into a USB power source delivering at least 2A of current.

Ensure that your car is *completely* powered off during software installation, otherwise you may get a "no panda" error.
To be sure that your car is completely powered down:
1. Turn the car on and off
2. Open and close the driver's door
3. Wait 5 minutes

## Known issues
* Curve hugging and laneline crossing are known issues of upstream openpilot.
* Officially supported cars (e.g. ACC Volt and Bolt) may have issues fingerprinting on OPGM. Currently, the only workaround is to hardcode your fingerprint in the `/data/openpilot/launch_openpilot.sh` file.

## Discussion
Come join us on the OPGM channel in the [openpilot community discord](https://discord.gg/KGWEdwSnCU)!

## Contributing
Feel free to open a pull request against the `dev` branch.

## Credits
* [comma.ai](https://comma.ai) for openpilot
* jshuler
* nworby
* twilsonco
* k1mu
* kliu
* mochi86420
* Many others

# License
OPGM is under the MIT license. See [LICENSE](LICENSE) for more information.
