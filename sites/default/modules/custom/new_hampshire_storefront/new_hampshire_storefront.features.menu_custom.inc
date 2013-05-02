<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function new_hampshire_storefront_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: admin
  $menus['admin'] = array(
    'menu_name' => 'admin',
    'title' => 'Admin',
    'description' => 'Administrative links.',
  );
  // Exported menu: devel
  $menus['devel'] = array(
    'menu_name' => 'devel',
    'title' => 'Development',
    'description' => 'Development links.',
  );
  // Exported menu: features
  $menus['features'] = array(
    'menu_name' => 'features',
    'title' => 'Features',
    'description' => 'Menu items for any enabled features.',
  );
  // Exported menu: menu-footer-nav-1
  $menus['menu-footer-nav-1'] = array(
    'menu_name' => 'menu-footer-nav-1',
    'title' => 'Footer Nav 1',
    'description' => 'Navigation on left side of footer',
  );
  // Exported menu: menu-footer-nav-2
  $menus['menu-footer-nav-2'] = array(
    'menu_name' => 'menu-footer-nav-2',
    'title' => 'Footer Nav 2',
    'description' => 'Navigation on right side of footer.',
  );
  // Exported menu: menu-home-nav
  $menus['menu-home-nav'] = array(
    'menu_name' => 'menu-home-nav',
    'title' => 'Home Navigation',
    'description' => 'Navigation on Home Page',
  );
  // Exported menu: menu-left-nav
  $menus['menu-left-nav'] = array(
    'menu_name' => 'menu-left-nav',
    'title' => 'Left navigation',
    'description' => 'The main site navigation after the splash page',
  );
  // Exported menu: navigation
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The navigation menu is provided by Drupal and is the main interactive menu for any site. It is usually the only menu that contains personalized links for authenticated users, and is often not even visible to anonymous users.',
  );
  // Exported menu: primary-links
  $menus['primary-links'] = array(
    'menu_name' => 'primary-links',
    'title' => 'Primary links',
    'description' => 'Primary links are often used at the theme layer to show the major sections of a site. A typical representation for primary links would be tabs along the top.',
  );
  // Exported menu: secondary-links
  $menus['secondary-links'] = array(
    'menu_name' => 'secondary-links',
    'title' => 'Secondary links',
    'description' => 'Secondary links are often used for pages like legal notices, contact details, and other secondary navigation items that play a lesser role than primary links',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin');
  t('Administrative links.');
  t('Development');
  t('Development links.');
  t('Features');
  t('Footer Nav 1');
  t('Footer Nav 2');
  t('Home Navigation');
  t('Left navigation');
  t('Menu items for any enabled features.');
  t('Navigation');
  t('Navigation on Home Page');
  t('Navigation on left side of footer');
  t('Navigation on right side of footer.');
  t('Primary links');
  t('Primary links are often used at the theme layer to show the major sections of a site. A typical representation for primary links would be tabs along the top.');
  t('Secondary links');
  t('Secondary links are often used for pages like legal notices, contact details, and other secondary navigation items that play a lesser role than primary links');
  t('The main site navigation after the splash page');
  t('The navigation menu is provided by Drupal and is the main interactive menu for any site. It is usually the only menu that contains personalized links for authenticated users, and is often not even visible to anonymous users.');


  return $menus;
}
