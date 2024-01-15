<?php
/**
 * @file
 * Create the readonly-mode command.
 */

/**
 * Implements hook_bee_command().
 */
function readonlymode_bee_command() {
  return array(
    'readonlymode' => array(
      'description' => bt('Enable or disable Read Only Mode for Backdrop.'),
      'callback' => 'readonlymode_bee_callback',
      'group' => 'miscellaneous',
      'arguments' => array(
        'value' => bt('A boolean value to enable (true/1) or disable (false/0) Read Only Mode. Omitting the value will return the current Read Only Mode status.'),
      ),
      'optional_arguments' => array('value'),
      'aliases' => array('ro', 'rom'),
      'bootstrap' => BEE_BOOTSTRAP_FULL,
      'examples' => array(
        'bee readonlymode true' => bt('Enable Read Only Mode for the site (not case-sensitive).'),
        'bee readonlymode FALSE' => bt('Disable Read Only Mode for the site (not case-sensitive).'),
        'bee readonlymode 1' => bt('Enable Read Only Mode for the site.'),
        'bee readonlymode 0' => bt('Disable Read Only Mode for the site.'),
        'bee readonlymode' => bt('Get the Read Only Mode status for the site.'),
      ),
    ),
  );
}

/**
 * Command callback: Set the value of readonly_mode for Backdrop.
 */
function readonlymode_bee_callback($arguments, $options) {
  // Check if a value has been provided.
  if (isset($arguments['value'])) {
    // Check for valid boolean value - allow true/false AND 1/0.
    $value = strtoupper($arguments['value']);
    switch ($value) {
      case 'TRUE':
      case '1':
        $value = (bool) TRUE;
        break;
      case 'FALSE':
      case '0':
        $value = (bool) FALSE;
        break;
      default:
        $err_msg = bt("'!value' is not a valid value. Enter 'TRUE', 'FALSE' (not case sensitive), '1' or '0'. Omit providing a value to get the current value.", array (
          '!value' => (string) $value,)
        );
        bee_message((string) $err_msg, 'error');
        return;
    }
    // Check if argument matches existing value.
    if ((bool) state_get('site_readonly', FALSE) == $value) {
      $msg = bt('Read Only Mode is already !value', array(
        '!value' => ($value) ? 'enabled' : 'disabled',
      ));
      bee_message((string) $msg, 'status');
    }
    else {
      // Attempt to set readonly mode.
      try {
        state_set('site_readonly', (bool) $value);
        $msg = bt('Read Only Mode was !value', array(
          '!value' => ($value) ? 'enabled' : 'disabled',
        ));
        bee_message((string) $msg, 'success');
      }
      catch (ParseError $e) {
        // This is more readable than the default error we would get from PHP.
        $err_msg = bt('!msg in: !value', array(
          '!msg' => $e->getMessage(),
          '!value' => $arguments['value'],
        ));
        bee_message((string) $err_msg, 'error');
      }
    }
  }
  else {
    // No value provided - get status.
    $value = (bool) state_get('site_readonly', FALSE);
    $msg = bt('Read Only Mode is !status', array(
      '!status' => ($value) ? 'enabled' : 'disabled',
    ));
    return array(
      array(
        'type' => 'text',
        'variables' => array(
          'value' => $msg,
        ),
        'newline' => TRUE,
      ),
    );
  }
}
