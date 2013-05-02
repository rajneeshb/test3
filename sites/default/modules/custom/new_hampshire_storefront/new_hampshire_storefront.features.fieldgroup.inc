<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function new_hampshire_storefront_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_administration
  $groups['order-group_administration'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_administration',
    'label' => 'Administration',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '6',
    'parent' => '',
    'fields' => array(
      '0' => 'field_creator',
      '1' => 'field_estimated_pages',
      '2' => 'field_actual_pages',
      '3' => 'field_copy_order',
      '4' => 'field_copy_page_desc',
      '5' => 'field_order_number',
      '6' => 'field_orderstatus',
      '7' => 'field_due_date',
      '8' => 'field_completiondate',
      '9' => 'field_completed_transcript',
      '10' => 'field_associated_parties',
      '11' => 'field_disable_notification',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_formats
  $groups['order-group_formats'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_formats',
    'label' => 'Format Options',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '53',
    'parent' => 'group_orderrequirements',
    'fields' => array(
      '0' => 'field_otherformats',
      '1' => 'field_numcopies',
    ),
    'depth' => 1,
    'parents' => array(
      '0' => 'group_orderrequirements',
    ),
  );

  // Exported group: group_header
  $groups['order-group_header'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_header',
    'label' => 'Tell us about your case:',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '1',
    'parent' => '',
    'fields' => array(
      '0' => 'field_casename',
      '1' => 'field_case_number',
      '2' => 'field_appealtranscript',
      '3' => 'field_appeal_number',
      '4' => 'field_locationref',
      '5' => 'field_witnesses',
      '6' => 'field_transcribeextra',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_hearingdates
  $groups['order-group_hearingdates'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'order',
    'group_name' => 'group_hearingdates',
    'label' => 'Estimated length of Hearing(s)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
      'multigroup' => array(
        'subgroup' => array(
          'weight' => -20,
          'label' => 'above',
          'teaser' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          'full' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          '4' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          '2' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          '3' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
          'token' => array(
            'format' => 'fieldset',
            'exclude' => 0,
          ),
        ),
        'multiple-columns' => 0,
        'required' => 1,
        'multiple' => '1',
        'labels' => array(
          '0' => '',
          '1' => '',
          '2' => '',
          '3' => '',
          '4' => '',
          '5' => '',
          '6' => '',
          '7' => '',
          '8' => '',
          '9' => '',
        ),
      ),
    ),
    'weight' => '36',
    'parent' => 'group_header',
    'fields' => array(
      '0' => 'field_hearingdate',
      '1' => 'field_estimatedhours',
      '2' => 'field_estimatedminutes',
    ),
    'depth' => 1,
    'parents' => array(
      '0' => 'group_header',
    ),
  );

  // Exported group: group_item_group
  $groups['order-group_item_group'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_item_group',
    'label' => 'Item group',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '54',
    'parent' => 'group_orderrequirements',
    'fields' => array(
      '0' => 'field_est_additional_cost',
      '1' => 'field_delivery_instructions',
    ),
    'depth' => 1,
    'parents' => array(
      '0' => 'group_orderrequirements',
    ),
  );

  // Exported group: group_orderdetails
  $groups['order-group_orderdetails'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_orderdetails',
    'label' => 'Order Summary',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '3',
    'parent' => '',
    'fields' => array(),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_orderrequirements
  $groups['order-group_orderrequirements'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_orderrequirements',
    'label' => 'Tell us what you need and when you need it:',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '2',
    'parent' => '',
    'fields' => array(
      '0' => 'field_turnaroundtime',
      '1' => 'field_est_transcript_cost',
      '2' => 'field_additional_comments',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_payment_information
  $groups['order-group_payment_information'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_payment_information',
    'label' => 'Payment Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '6',
        'parent' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '4',
    'parent' => '',
    'fields' => array(
      '0' => 'field_how_to_pay',
      '1' => 'field_private_pay_info',
      '2' => 'field_court_pay_info',
      '3' => 'field_deposit_required',
      '4' => 'field_estimated_cost',
      '5' => 'field_actual_cost',
      '6' => 'field_deposit_paid',
      '7' => 'field_deposit_paid_date',
      '8' => 'field_balance_due',
      '9' => 'field_balance_paid',
      '10' => 'field_balance_paid_date',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: group_user
  $groups['order-group_user'] = array(
    'group_type' => 'standard',
    'type_name' => 'order',
    'group_name' => 'group_user',
    'label' => 'User Account',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'You must login, or create a new account, to submit this order. Your e-mail address is not made public and will only be used for you to receive notifications about the status of your Order or if you wish to receive a new password.',
      ),
      'display' => array(
        'description' => 'You must login, or create a new account, to submit this order. Your e-mail address is not made public and will only be used for you to receive notifications about the status of your Order or if you wish to receive a new password.',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '5',
    'parent' => '',
    'fields' => array(
      '0' => 'field_create_or_login',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Exported group: personal_information
  $groups['profile-personal_information'] = array(
    'group_type' => 'standard',
    'type_name' => 'profile',
    'group_name' => 'personal_information',
    'label' => 'Personal Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '0',
        'parent' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'parent' => '',
    'fields' => array(
      '0' => 'field_court_location_groups',
      '1' => 'field_first_name',
      '2' => 'field_last_name',
      '3' => 'field_address',
      '4' => 'field_company_firm',
      '5' => 'field_daytime_phone',
      '6' => 'field_comments',
    ),
    'depth' => 0,
    'parents' => array(
      '0' => '',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Administration');
  t('Estimated length of Hearing(s)');
  t('Format Options');
  t('Item group');
  t('Order Summary');
  t('Payment Information');
  t('Personal Information');
  t('Tell us about your case:');
  t('Tell us what you need and when you need it:');
  t('User Account');

  return $groups;
}
