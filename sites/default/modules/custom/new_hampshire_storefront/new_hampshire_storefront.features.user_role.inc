<?php

/**
 * Implementation of hook_user_default_roles().
 */
function new_hampshire_storefront_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
  );

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  // Exported role: authenticated user
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
  );

  // Exported role: avtranz
  $roles['avtranz'] = array(
    'name' => 'avtranz',
  );

  // Exported role: content provider
  $roles['content provider'] = array(
    'name' => 'content provider',
  );

  // Exported role: customer
  $roles['customer'] = array(
    'name' => 'customer',
  );

  // Exported role: supervisor
  $roles['supervisor'] = array(
    'name' => 'supervisor',
  );

  return $roles;
}
