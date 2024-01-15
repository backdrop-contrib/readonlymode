# Read Only Mode
<!--
The first paragraph of this file should be kept short as it will be used as the
project summary on BackdropCMS.org. Aim for about 240 characters (three lines at
80 characters each).

All lines in this file should be no more than 80 characters long for legibility,
unless including a URL or example that requires the line to not wrap.
|<- - - - - - - This line is exactly 80 characters for reference - - - - - - ->|

Detail in READMEs should be limited to the minimum required for installation and
getting started. More detailed documentation should be moved to a GitHub wiki
page; for example: https://github.com/backdrop-contrib/setup/wiki/Documentation.
-->
Read Only Mode allows site administrators and developers to lock down or
freeze a production server so that maintenance or large deployments can occur
without taking the site offline.

In a typical example, Read Only Mode is activated on the production server,
the database is copied to a development server where work is done, and then the
database is pushed back to the production server and Read Only Mode disabled.

Read Only Mode can be checked, enabled or disabled using the user interface,
bee or drush.

## Installation
<!--
List the steps needed to install and configure the module. Add/remove steps as
necessary.
-->
- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.

- Visit the configuration page under Administration > Configuration >
Development > Maintenance mode (admin/config/development/maintenance) to
customize settings.

### Differences from Drupal 7
- Uses 'state' and 'config' rather than 'variables'.
- Form IDs updated in allow/view only lists to reflect Backdrop equivalents.
- Dedicated Bee command added to simply operations.
- Drush command uses `state-set` and `state-get` rather than `variable-set` and
`variable-get`.
- Includes patch from [Issue 2458051](https://www.drupal.org/project/readonlymode/issues/2458051)
to fix issue with View Only forms.
- Includes an API for other modules to modify the default form lists.

## Usage
Enable and disable Read Only Mode using the "Read only mode" checkbox at
Administration > Configuration > Development > Maintenance mode
(admin/config/development/maintenance).

On this page, it is also possible to:
- Customize the messages that are shown to users when Read Only Mode is
enabled.
- Redirect users to a specific page instead of showing messages.
- Define additional forms that are allowed using the form id.
- Define additional forms that can be accessed as view only forms.

You may want to allow other forms if the form does not write to the Backdrop
database, but instead sends the form content to a different web service or by
email.

You may want to allow other forms to be viewed but not changed so users can
check details but not make changes.

The module provides a permission that overrides access restrictions and can be
given to administrators; user 1 can access all forms regardless of the
permission.

### Bee support
This module adds a dedicated bee command to enable, disable and check status of
Read Only Mode. It can be used with `bee readonlymode`, `bee ro` or `bee rom`.

The command will treat `1`, `true`, `TRUE` as `TRUE` and `0`, `false`, `FALSE`
as `FALSE`.

- Check the status:         `bee readonlymode`
- Turn on Read Only Mode:   `bee readonlymode 1`
- Turn off Read Only Mode:  `bee readonlymode 0`

### Drush support
As Read Only Mode is defined by a single state, it is easy to use Drush
to enable and disable the mode. Drush aliases `sget` and `sset` will also work
here.

- Check the status:         `drush state-get site_readonly`
- Turn on Read Only Mode:   `drush state-set site_readonly 1`
- Turn off Read Only Mode:  `drush state-set site_readonly 0`

### API support
The module has an API to support modification of the lists of allowed forms and
view only forms by other contrib and custom modules. See `readonlymode.api.php`
for more details.

Issues
------
<!--
Link to the repo's issue queue.
-->
Bugs and Feature Requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/readonlymode/issues.


Current Maintainers
-------------------
<!--
List the current maintainer(s) of the module, and note if this module needs
new/additional maintainers.
-->
- [Martin Price](https://github.com/yorkshire-pudding) - [System Horizons Ltd](https://www.systemhorizons.co.uk)
- Collaboration and co-maintainers welcome!

Credits
-------
<!--
Give credit where credit's due.
If this is a Drupal port, state who ported it, and who wrote the original Drupal
module. If this module is based on another project, or uses third-party
libraries, list them here. You can also mention any organisations/companies who
sponsored the module's development.
-->
- Ported to Backdrop CMS by - [Martin Price](https://github.com/yorkshire-pudding) - [System Horizons Ltd](https://www.systemhorizons.co.uk).
- Port sponsored by [System Horizons Ltd](https://www.systemhorizons.co.uk).
- Originally written for Drupal by [Sharique Farooqui](https://www.drupal.org/u/sharique)

License
-------
<!--
Mention what license this module is released under, and where people can find
it.
-->

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.