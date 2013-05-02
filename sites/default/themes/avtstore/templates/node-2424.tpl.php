<?php
  $links = array();

  $links['Orders'] = array();
  $links['Users'] = array();
  $links['Groups'] = array();

  if ( user_access('view order administration list') ) {
    // if admin or supervisor
    $links['Orders'][] = l( t('View Admin listing of Orders'), 'checkstatusadmin');
    $links['Orders'][] = l( t('View Admin listing of Orders by Anonymous user'), 'reports/orders/ghosts');
  }
  elseif ( user_access('view order administration list by location') ) {
    // if content provider
    $links['Orders'][] = l( t('View Admin listing of Orders'), 'checkstatusadminlocation');
  }

  if ( user_access('administer users') ) {
    // if admin or supervisor
    $links['Users'][] = l( t('View list of users to administer'), 'admin_user');
    $links['Users'][] = l( t('Add new user'), 'admin/user/user/create');
  }

  if ( user_access('create content_provider_group content') ) {
    // if admin or supervisor
    $links['Groups'][] = l( t('View list of groups to administer'), 'grouplistadmin');
    $links['Groups'][] = l( t('Add new group'), 'node/add/content-provider-group');
  }

  foreach ($links as $section => $links) {
    if ( !empty($links) ) {
      echo theme('item_list', $links, $section);
    }
  }
