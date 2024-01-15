<?php
/**
 * @file
 * Sample hooks demonstrating how the default form allow lists and default form
 * view only lists can be modified by other contrib modules or custom modules.
 */

/**
 * Modify the forms allowed during read-only mode.
 *
 * @param array &$default_forms_allowed
 *   Array passed by reference of the default forms allowed so this list can be
 *   added to and/or removed from.
 *
 * @return array
 */
function hook_readonlymode_default_forms_allowed_alter(array &$default_forms_allowed) {
  // Add additional forms.
  $default_forms_allowed = array_merge(
    $default_forms_allowed, array(
      'my_module_form_id',
    )
  );

  // Remove default form.
  unset($default_forms_allowed['system_modules']);

  // Return the modified array.
  return $default_forms_allowed;
}

/**
 * Modify the forms allowed for view only during read-only mode.
 *
 * @param array &$default_forms_viewonly
 *   Array passed by reference of the default forms allowed for view only so
 *   this list can be added to and/or removed from.
 *
 * @return array
 */
function readonlymode_default_forms_viewonly(array &$default_forms_viewonly) {
  // Add additional forms.
  $default_forms_viewonly = array_merge(
    $default_forms_viewonly, array(
      'my_module_form_id',
    )
  );

  // Remove default form.
  unset($default_forms_viewonly['views_form_user_admin_page']);

  // Return the modified array.
  return $default_forms_viewonly;
}
